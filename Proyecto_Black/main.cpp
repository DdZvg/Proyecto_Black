
//#include "blackJackgame.h"
//#include "testCarta.h"
//#include "Consola.h"
//#include <iostream>
//
//using namespace std;   
//
//int main(){
//    //  test
//    Consola::limpiarPantalla();
//    ejecutarPruebasCarta();
//
//
//
//    return 0;
//
//}
#include "Consola.h"
#include "Menu.h"
#include "testMenu.h"
#include <iostream>

using namespace std;

const bool MODO_TEST_MENU = true;

int main() {
    Consola::inicializar();

    if (MODO_TEST_MENU) {
        TestMenu::ejecutarTodasLasPruebas();
        return 0;
    }

    Menu menu("BlackProject");
    Menu menu("BlackProject");
    Menu menu("BlackProject");
    menu.mostrarBienvenida();

    return 0;
}