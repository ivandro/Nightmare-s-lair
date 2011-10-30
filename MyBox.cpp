#include "MyBox.h"

namespace example {

	MyBox::MyBox(std::string id):

		cg::Entity(id),
		_movable( true ),
		_isDebug( false ),
		m_lastMousePosition( 0.0, 0.0, -1.0 ) {
	}

	MyBox::~MyBox() {
	}

	// porque � que est� fun��o � inline? 
	// Qual � a diferen�a entre o x0 e x1, y0 e y1?
	// O que � o par�metro n? 
	// O que s�o os par�metros nx, ny e nz? normal?
	// nome da fun��o � muito esquecito! plano dividido? o que � isso? 
	// A fun��o n�o � um predicado( n�o devolve um booleano ) logo realiza uma ac��o no presente! Seria mais f�cil se o nome estivesse no infinitivo ou no presente? 
	inline 
	void MyBox::dividedPlane(int n, 
		double x0, double y0, double x1, double y1,
		double nx, double ny, double nz) 
	{
		int countx = 0;	// O que � que est� vari�vel faz? contagem de x? o que � que isso significa?
		int county = 0; // O que � que est� vari�vel faz? contagem de y? o que � que isso significa?
		double x = x0; 
		double y = y0;
		double stepx = (x1-x0)/(double)n; 
		double stepy = (y1-y0)/(double)n;

		glBegin(GL_QUADS);
		glNormal3d(nx,ny,nz);	// Aqui descobri que nx, ny e nz s�o realmente as normais! Seria mais f�cil compreender o sentido dessas vari�veis se fossem renomeadas normalX, normalY, normalZ? ( aumenta apenas 5 letras ao tamanho da palavra )

		// o que � o n? e o que � o countx e county? ainda n�o sei! :S. N�o estou a perceber os ciclos!
		while (countx != n) {
			while (county != n) {
				glVertex3d(x, 0, y);		// A vari�vel tem o nome y, mas � utilizada como z? Seria mais f�cil renomear a vari�vel como z? opengl utiliza o z quando devia utilizar o y? ou isto � uma verifica��o que o implementador reparou nesta situa��o? Seria melhor n�o colocar excep��es a regra? ou ent�o documentar bem esses casos?
				glVertex3d(x+stepx, 0, y);  // N�o consigo ter uma imagem do que resulta o conjunto dos vertices! suponho que um quadrado pois o glBegin est� no modo GL_QUADS. Seria melhor se cada instru��o glVertex3d indicasse que parte do quadrado � o vertice? 
				glVertex3d(x+stepx, 0, y+stepy);
				glVertex3d(x, 0, y+stepy);
				county++;
				y += stepy;				
			}
			countx++;
			x += stepx;			
			county = 0;
			y = y0;			
		}

		glEnd();
	}

	
	inline
	void MyBox::makeModel() {
		_modelDL = glGenLists(1);
		assert(_modelDL != 0);
		glNewList(_modelDL,GL_COMPILE);

		//REMOVE 	 	 	 	 	 	 	 	 	
  glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialBank::getAmbientVec(MaterialBank::MATERIAL_COPPER));
  glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialBank::getDiffuseVec(MaterialBank::MATERIAL_COPPER));
  glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialBank::getSpecularVec(MaterialBank::MATERIAL_COPPER));
  glMaterialf(GL_FRONT, GL_SHININESS, MaterialBank::getShininess(MaterialBank::MATERIAL_COPPER));
		//REMOVE 

			// TOP
			glPushMatrix();
				glTranslatef(0,1,0);
				dividedPlane(10, -1,-1,1,1, 0,1,0);
			glPopMatrix();
			// BOTTOM
			glPushMatrix();
				glTranslatef(0,-1,0);
				glRotatef(180, 1,0,0);
				dividedPlane(10, -1,-1,1,1, 0,1,0);
			glPopMatrix();
			// LEFT
			glPushMatrix();
				glTranslatef(0,0,1);
				glRotatef(90,1,0,0);
				dividedPlane(10, -1,-1,1,1, 0,1,0);
			glPopMatrix();
			// RIGHT
			glPushMatrix();
				glTranslatef(0,0,-1);
				glRotatef(-90,1,0,0);
				dividedPlane(10, -1,-1,1,1, 0,1,0);
			glPopMatrix();
			// FRONT
			glPushMatrix();
				glTranslatef(1,0,0);
				glRotatef(-90,0,0,1);
				dividedPlane(10, -1,-1,1,1, 0,1,0);
			glPopMatrix();
			// BACK
			glPushMatrix();
				glTranslatef(-1,0,0);
				glRotatef(90,0,0,1);
				dividedPlane(10, -1,-1,1,1, 0,1,0);
			glPopMatrix();
		glEndList();
	}
	void MyBox::init() {
		//_physics.setPosition(3,1.01,-3);
		_physics.setAngularVelocity(1000); //considerar sizeOfBlock/2 em x de 10  
		_physics.setLinearVelocity(100); 
		//_lastposition = _physics.getPosition(); Remove
		makeModel();
	}
	void MyBox::update(unsigned long elapsed_millis) {
		if(_movable && !_isDebug){
			if(cg::KeyBuffer::instance()->isKeyDown('w')) {
				_physics.goAhead();		
		
			}
			if(cg::KeyBuffer::instance()->isKeyDown('s')) {
				
				_physics.goBack();	
		
			}
			if(cg::KeyBuffer::instance()->isKeyDown('a')) {
				_physics.strafeLeft();
			}
			if(cg::KeyBuffer::instance()->isKeyDown('d')) {
				_physics.strafeRight();
			}
			// _lastposition.set(_physics.getPosition()); REMOVE
			MyFPSCamera * fps = (MyFPSCamera *) cg::Registry::instance()->get("FPSCamera");
			fps->setPosition(_physics.getPosition());

			double elapsed_seconds = elapsed_millis / (double)10000;
			_physics.step(elapsed_seconds);
		}
	}

	void MyBox::onMousePassiveMotion(int x, int y) {

	}

	int drawPasses = 100;

	void MyBox::draw() {

		// put the matrix mode to modelview
		
		glMatrixMode( GL_MODELVIEW );
		// safe the actual modelview matrix
		
		glPushMatrix();
		// get the camera unchanged modelview matrix
		// put the unchanged matrix as the currently matrix
		
		MyFPSCamera *fps = (MyFPSCamera *) cg::Registry::instance()->get( "FPSCamera" );
		glLoadMatrixd( fps->getUnchangedMVMatrix() );

		// change the direction of the box to be equal to the direction of the camera

		cg::Vector3d *newFront = new cg::Vector3d( cos( fps->getRotationX() * degreeToRadianus ), 0.0, sin( fps->getRotationX() * degreeToRadianus ) );
		cg::Vector3d *newRight = new cg::Vector3d( -sin( fps->getRotationX() * degreeToRadianus ), 0.0, cos( fps->getRotationX() * degreeToRadianus ) );

		_physics.setFront ( *newFront );
		_physics.setRight( *newRight );

		glPushMatrix();
			_physics.applyTransforms();
			glCallList(_modelDL);
		glPopMatrix();

		// pop the unchanged matrix

		glPopMatrix();

	}

	void MyBox::togglemovable(){
		_movable = !_movable;
	}

	void MyBox::toggleDebugMode() {
		_isDebug = !_isDebug;
	}

}