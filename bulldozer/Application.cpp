#include "Application.h"

Application::Application(void) : Kernel() {
   setWindowSize(1050, 800);
   lockWindowSize(false);
   setFramesPerSecond(60);

   setWindowTitle("SCV v4.2 - FreeForm Interface Designer");
}

Application::~Application(void) {
}

void Application::init(void) {
   _mainPanel = new scv::Panel(scv::Point(0, 0), scv::Point(1050, 800));

   addComponent(_mainPanel);

    

  

   MyCanvas *canvas0 = new MyCanvas();
   addComponent(canvas0);

   canvas1 = new MyCanvas2();
   addComponent(canvas1);

   MyButton *button0 = new MyButton(scv::Point(13,156), scv::Point(102, 180),canvas0,canvas1);
   addComponent(button0);

   MyButton2 *button1 = new MyButton2(scv::Point(13,200), scv::Point(102, 240),canvas0,canvas1);
   addComponent(button1);


   MyButton3 *button2 = new MyButton3(scv::Point(13,290), scv::Point(102, 310),canvas0,canvas1);
   addComponent(button2);

   MyButton4 *button3 = new MyButton4(scv::Point(13,400), scv::Point(102, 440),canvas0,canvas1);
   addComponent(button3);

   scv::Label *label0 = new scv::Label(scv::Point(182,689), scv::Point(258, 702), "Desenhe aqui os pontos");
   addComponent(label0);

   scv::Label *label1 = new scv::Label(scv::Point(687,680), scv::Point(763, 693), "solido gerado");
   addComponent(label1);
   
   scv::Label *label2 = new scv::Label(scv::Point(13,320), scv::Point(763, 390), "mola em perspectiva");
   addComponent(label2);
   
   scv::Label *label3 = new scv::Label(scv::Point(20,450), scv::Point(763, 490), "resetar pontos");
   addComponent(label3);

    scv::Label *label4 = new scv::Label(scv::Point(13,120), scv::Point(102, 140), "gera objeto");
   addComponent(label4);

}

void Application::onMouseClick(const scv::MouseEvent &evt) {
}
void Application::onMouseHold(const scv::MouseEvent &evt) {
}
void Application::onMouseOver(const scv::MouseEvent &evt) {
}
void Application::onMouseUp(const scv::MouseEvent &evt) {
}
void Application::onMouseWheel(const scv::MouseEvent &evt) {
}

void Application::onKeyPressed(const scv::KeyEvent &evt) {
		
}
void Application::onKeyUp(const scv::KeyEvent &evt) {
}

void Application::onSizeChange(void) {
   _mainPanel->setSize(getWidth(), getHeight());
}
void Application::onPositionChange(void) {
}
