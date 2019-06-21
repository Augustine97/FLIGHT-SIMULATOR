#include <windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include <GL/glut.h>
static double x[10]={0},x2=0.0,r1=0.0;
static double yaxis[10]={-15,-15,-15,-15,-15,-15,-15,-15,-15,-15};
static double max=0;
static bool takeOff=false;


void stroke_output(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(-2.5, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}


 
//runway strip
void strip(float x1)
{
glPushMatrix();
glRotatef(-65,0,1,0);
glColor3f(1,1,1);
glTranslatef(x1,-3.5,7.8);
glScaled(1,0.15,0.1);
glutSolidCube(1);
glPopMatrix();
}



void drawPlane(float y1){


/***********  PLANE CONSTRUCTION  *******************/	
	glPushMatrix();
	

	// Main Body 
glPushMatrix();
glScalef(.3,0.3,1.5);
if(y1<=15)
glColor3f(1,1.0,0.5);
if(y1>=15)
glColor3f(1,0.3,0.5);

glutSolidSphere(2.0,50,50);
glPopMatrix();

 glPushMatrix();
 glTranslatef(0.0,0.1,-1.8);
glScalef(1.0,1,1.5);
glColor3f(0,0,1);
glutSolidSphere(0.5,25,25);
glPopMatrix();


//Left Fin

glPushMatrix();
glTranslatef(-1.0,0,0);
glScalef(1.5,0.1,0.5);
glColor3f(0,0,0);
glutSolidSphere(1.0,50,50);
glPopMatrix();

// Right Fin
glPushMatrix();

glTranslatef(1.0,0,0);
glScalef(1.5,0.1,0.5);
glColor3f(0,0,0);
glutSolidSphere(1.0,50,50);
glPopMatrix();

//right Tail fin
glPushMatrix();

glTranslatef(0.8,0,2.4);
glScalef(1.2,0.1,0.5);
glColor3f(0.0,0,0);
glutSolidSphere(0.4,50,50);
glPopMatrix();

//left Tail fin
glPushMatrix();
glTranslatef(-0.8,0,2.4);
glScalef(1.2,0.1,0.5);
glColor3f(0.0,0,0);
glutSolidSphere(0.4,50,50);
glPopMatrix();

//Top tail fin
glPushMatrix();
glTranslatef(0,0.5,2.4);
glScalef(0.1,1.1,0.5);
glColor3f(0.0,0,0);
glutSolidSphere(0.4,50,50);
glPopMatrix();

// Blades
glPushMatrix();
glRotatef(x2,0.0,0.0,1.0);
glPushMatrix();
glTranslatef(0,0.0,-3.0);
glScalef(1.5,0.2,0.1);
glColor3f(0.0,0,0);
glutSolidSphere(0.3,50,50);
glPopMatrix();

//blades
glPushMatrix();
glRotatef(90,0.0,0.0,1.0);
glTranslatef(0,0.0,-3.0);
glScalef(1.5,0.2,0.1);
glColor3f(0.0,0,0);
glutSolidSphere(0.3,50,50);
glPopMatrix();

glPopMatrix();
/* Blased End */

/*   Wheels   */
//Front


glPushMatrix();
glTranslatef(0.0,-0.8,-1.5);
glRotatef(90,0.0,1,0);
glScaled(0.3,0.3,0.3);
glutSolidTorus(0.18,0.5,25,25);
glColor3f(1,1,1);
glutSolidTorus(0.2,0.1,25,25);

glPopMatrix();

glPushMatrix();
glTranslatef(0.0,-0.4,-1.5);
glRotatef(20,0.0,1,0);
glScaled(0.05,0.3,0.05);
glutSolidSphere(1.0,25,25);
glPopMatrix();


//Rear 

glPushMatrix();
glTranslatef(0.3,-0.8,0.7);
glRotatef(90,0.0,1,0);
glScaled(0.3,0.3,0.3);
glColor3f(0,0,0);
glutSolidTorus(0.18,0.5,25,25);
glColor3f(1,1,1);
glutSolidTorus(0.2,0.1,25,25);
glPopMatrix();

glPushMatrix();
glTranslatef(0.3,-0.4,0.7);
glRotatef(20,0.0,1,0);
glScaled(0.05,0.3,0.05);
glutSolidSphere(1.0,25,25);
glPopMatrix();

//rear 2
glPushMatrix();
glTranslatef(-0.3,-0.8,0.7);
glRotatef(90,0.0,1,0);
glScaled(0.3,0.3,0.3);
glColor3f(0,0,0);
glutSolidTorus(0.18,0.5,25,25);
glColor3f(1,1,1);
glutSolidTorus(0.2,0.1,25,25);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.3,-0.4,0.7);
glRotatef(20,0.0,1,0);
glScaled(0.05,0.3,0.05);
glutSolidSphere(1.0,25,25);
glPopMatrix();



glPopMatrix();



}


void animate(float y1,float x1){


	// Plane Transition
	glPushMatrix();
	//Move  the Plane towards rotating zone
	if(y1<=-2){
	glTranslatef(5.5+y1,3,0);
	glRotatef(-90,0,1,0);	
	}

	// Move the Plane towards 2nd runwat
if(takeOff)
	if(y1>=15){
	glRotatef(140,0,1,0);
		
		if(y1>=15 && y1<=20)
		glTranslatef(2+15-y1,-3,-3);
		
		if(y1>=20)
		glTranslatef(2+15-y1,-3-20+y1,-3);
		
	}


	// keep rotating the plane
	if(y1>=-2 && y1<=2){
	glTranslatef(3.0,3.0,0.0);
	}
	//Start desending the plane 
	if(y1>=2 && y1<=6.5)
	{
	glTranslatef(3,3-y1+2,0);
	}
	// move towards runway
	if(y1>=6.5 && y1<=8.2)
	{
	glTranslatef(3-y1+6.5,3-y1+2,0);
	}
	// landing only change the x-axis
		if(y1>=8.2 && y1<=15)
	{
	glTranslatef(3-y1+6.5,3-8.2+2,0);
	}
	
	// Rotate the plane about its own axiz w.r.t y-axis.
	if(y1>=-2)
	glRotatef(x1,0,1,0);

	glPushMatrix();
	//Move the plane away from its axis 
	glTranslatef(1,0,0);

	glScaled(0.3,0.3,0.15);
	//tilt the plane until its being rotated
	if(y1<=8.2)

	if(yaxis[0]>=-2)
	glRotatef(15,0,0,1);
	

	if(y1<=15){
	drawPlane(y1);
	}
	
	if(y1>=15 && takeOff){
		
	drawPlane(y1);
	}

	glPopMatrix();

    glPopMatrix();
	


}

void airport(){

	//Floor
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
glVertex3f(-19,-3.5,19);
glVertex3f(-19,-3.5,-19);
glVertex3f(19,-3.5,-19);
glVertex3f(19,-3.5,19);
	glEnd();

glPushMatrix();

// runway landing 

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(0,-3.5,-1);
glScaled(17,0.1,1);
glutSolidCube(1);
glPopMatrix();


// runway takeoff 

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(-0.5,-3.5,4);
glRotatef(-60,0,1,0);
glScaled(11,0.1,1);
glutSolidCube(1);
glPopMatrix();

// runway + parking 

glPushMatrix();
glRotatef(-65,0,1,0);
glColor3f(0.1,0.1,0.1);
glTranslatef(3,-3.5,7.8);
glScaled(15.5,0.1,1);
glutSolidCube(1);
glPopMatrix();

//parking place 1
glPushMatrix();
glRotatef(-65,0,1,0);
glColor3f(0.1,0.1,0.1);
glTranslatef(-1,-3.5,7);
glScaled(2.5,0.1,1.5);
glutSolidCube(1);
glPopMatrix();

//parking plane 1
glPushMatrix();
glRotatef(-65,0,1,0);
glTranslatef(3,-2.7,7.4);
glScaled(0.15,0.3,0.15);
drawPlane(16);
glPopMatrix();

//parking place 2
glPushMatrix();
glRotatef(-65,0,1,0);
glColor3f(0.1,0.1,0.1);
glTranslatef(3,-3.5,7);
glScaled(2.5,0.1,1.5);
glutSolidCube(1);
glPopMatrix();

//parking plane 2
glPushMatrix();
glRotatef(-65,0,1,0);
glTranslatef(6.5,-2.7,7.4);
glScaled(0.15,0.3,0.15);
drawPlane(16);
glPopMatrix();

//parking place 3
glPushMatrix();
glRotatef(-65,0,1,0);
glColor3f(0.1,0.1,0.1);
glTranslatef(7,-3.5,7);
glScaled(2,0.1,1.5);
glutSolidCube(1);
glPopMatrix();

//parking plane 3
glPushMatrix();
glRotatef(-65,0,1,0);
glTranslatef(10,-2.7,7.4);
glScaled(0.15,0.3,0.15);
drawPlane(16);
glPopMatrix();

// parking building 

glPushMatrix();
glRotatef(-65,0,1,0);
glColor3f(0,0.5,0.5);
glTranslatef(4,-3.5,5.5);
glScaled(14,2.2,1);
glutSolidCube(1);

glPushMatrix();
//glRotatef(15,0,1,0);
glTranslatef(0,0.3,0);
glScaled(0.9,0.3,1);
glColor3f(0.1,0.1,0.1);
glutSolidCube(1);
glPopMatrix();

glPopMatrix();




strip(-2);
strip(0);
strip(2);
strip(4);
strip(6);
strip(8);
strip(10);

// runway Lights
for(float j=-1.3;j<=-0.5;j+=0.8)
{	
for(float i=-4.5;i<=1.8;i+=0.9){

glPushMatrix();
glColor3f(1,0,0);
glTranslatef(i,-3.4,j);
//glScaled(6,0.2,1);
glutSolidSphere(0.05,10,10);
glPopMatrix();
}}


glTranslatef(7,0,-4);
// Building
	glPushMatrix();
	glTranslatef(-2,-3,-2);
	glutSolidCube(1);
	glPopMatrix();


	//Rotating Dish
	glPushMatrix();
	glColor3f(0,0,1);
	glTranslatef(-2,-2.0,-2);
	glRotatef(x2/15,0,1,0);
	glScaled(0.1,0.3,1);
	glutSolidCube(1);
	glPopMatrix();
//dish connector
	glPushMatrix();
	glColor3f(0,0,1);
	glTranslatef(-2,-2.5,-2);
	glScaled(0.1,0.9,0.1);
	glutSolidCube(1);
	glPopMatrix();

glPopMatrix();
//Mountain
	glPushMatrix();
	glColor3f(0.2,0.2,0.2);
	glTranslatef(-3,-3,-15);
	glScaled(10,4,1);
	glutSolidDodecahedron();
	glPopMatrix();
	



}

// Start your Drawing ---Draw pyramid

void controller()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	glTranslatef(0.0,0.0,-25.0);
//q	glRotatef(-90,0,1,0);
	

	animate(yaxis[0],x[0]);


	for(int i=0;i<max;i++){
	if(yaxis[i]>=-5){		//wait until previous plane reaches safe location
	animate(yaxis[i+1],x[i+1]);	
	if(yaxis[i+1]>=-2 && yaxis[i+1]<=6.7)	
	// Rotate until y-axis of plane is less than 6.7
	x[i+1]+=3.5;

	// Conditions to increase or decrease the speed of plane
	if(yaxis[i+1]<=0)
	yaxis[i+1]+=0.15;

	else if(yaxis[i+1]>=0 && yaxis[i+1]<=6.7)
	
		yaxis[i+1]+=0.06;
	
	else if(yaxis[i+1]>=6.7 && yaxis[i+1]<=15)
	
		yaxis[i+1]+=0.1;
	
	else if(takeOff && yaxis[i+1]<=30)
	
		yaxis[i+1]+=0.1;

	}

	}
	
	airport();


	x2+=15.0; // Rotate the plane blades
	
	// Increments of First plane

	if(yaxis[0]>=-2 && yaxis[0]<=6.7)
	
	x[0]+=3.5; // used to rotate the plane
	
	 //Translate the plane

	// Conditions to increase or decrease the speed of first plane
	if(yaxis[0]<=0)
	
	yaxis[0]+=0.15;
	
	else if(yaxis[0]>=0 && yaxis[0]<=6.7)

	yaxis[0]+=0.06;
	
	else if(yaxis[0]>=6.7 )
	
	yaxis[0]+=0.1;

	

	



    glFlush();
    glutSwapBuffers();

}




void doInit() 
{
    
	/* Background and foreground color */
    glClearColor(1.0,1.0,1.0,0.0);
    
    glViewport(0,0,640,480);
 
	/* Select the projection matrix and reset it then
     setup our view perspective */

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
	gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);  
	
    /* Select the modelview matrix, which we alter with rotatef() */
    glMatrixMode(GL_MODELVIEW);
    
	glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-13.0f);
	
	stroke_output(-2.0, 1.7, "p--> Pyramid Clockwise");
		stroke_output(-2.0, 1.0, "P--> Pyramid Anti Clockwise");
			stroke_output(-2.0, 0.3, "h--> House Clockwise");
				stroke_output(-2.0, -0.4, "H--> House Anti-Clockwise");
					stroke_output(-2.0, -1.1, "q--> quit");
	

	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	GLfloat lightIntensity[]={3.7f,0.7f,0.7f,1.0f}; 
	
	GLfloat light_position[]={0.0f,3.0f,2.0f,0.0f};
	
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
	
	
	glutIdleFunc(controller);


	glFlush();
	glutSwapBuffers();
    
}

void menu(int id)
{
	switch(id)
	{
	case 1:max+=1;
		break;

	case 2:max-=1;
		break;

	case 3:takeOff=!takeOff;
		break;

	case 4:exit(0);
		break;
	
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void mykey(unsigned char key,int x,int y)
{
	

	if(key=='p')
	{
		glutIdleFunc(controller);
	}

	
	if(key=='f')
	{
		takeOff=!takeOff;
	}

	if(key=='a')

	{
		max+=1;
	}
	
	
	if(key=='r')

	{
		max-=1;
	}
	

	if(key=='q'|| key=='Q')
	{
		exit(0);
	}

	
}

int main(int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    
	glutInitWindowSize(1000,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Glut Plane");
    
	glutDisplayFunc(display);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glutKeyboardFunc(mykey);
	
	glutCreateMenu(menu);

    glutAddMenuEntry("Add Plane       'a'",1);
	glutAddMenuEntry("Remove          'r'",2);
	glutAddMenuEntry("Takeoff         'f'",3);
	glutAddMenuEntry("Quit            'q'",4);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
doInit();

    glutMainLoop();
	return 0; 
}

