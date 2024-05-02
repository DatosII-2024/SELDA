#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "glog/logging.h"

using namespace sf;

int main (){
    RenderWindow window(VideoMode(800,600),"SELDA");

    Texture texture;
    if(!texture.loadFromFile("/home/erick/Datos II/SELDA/img/a1.jpg")){
        LOG(ERROR)<<"No se cargo correctamente la imagen";
        return EXIT_FAILURE;
    }
    Sprite sprite(texture);

    Font font;
    if(!font.loadFromFile("/home/erick/Datos II/SELDA/fonts/Menu.ttf")){
        LOG(ERROR)<<"No se cargo correctamente la fuente";
        return EXIT_FAILURE;
    }
    Text text("SELDA",font,50);

    SoundBuffer bufer,swo,scu;
    if(!bufer.loadFromFile("/home/erick/Datos II/SELDA/sounds/D.ogg")||
    !swo.loadFromFile("/home/erick/Datos II/SELDA/sounds/S.ogg")||
    !scu.loadFromFile("/home/erick/Datos II/SELDA/sounds/m.ogg")){
        LOG(ERROR)<<"No se cargo correctamente la musica";
        return EXIT_FAILURE;
    }
    Sound sound,sword,scudo;
    sound.setBuffer(bufer);
    sword.setBuffer(swo);
    scudo.setBuffer(scu);
    sound.play();

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
           if(event.type == Event::Closed){
               window.close();
           }
           if (event.key.code==Keyboard::Space){
               sword.play();
           }
           if(event.key.code==Keyboard::LShift){
               scudo.play();
           }
        }

        window.clear();

        window.draw(sprite);

        window.draw(text);

        window.display();
    }

    return 0;
}
