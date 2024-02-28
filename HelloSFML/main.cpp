
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace sf;
using namespace std;

int main() {


   //------------------------------------------------------- Window/Border/Text

   // set window size
   const int window_width = 900;
   const int window_height = 700;

   // sets border size
   const int borders_width = 383;
   const int borders_height = 700;

   // Creates the window environment
   sf::RenderWindow window(sf::VideoMode(window_width, window_height), "TETRIS");


   //Credit to Pixesia Studio for the font
   // Inserts specialized font using link
   sf::Font font;
   if(!font.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/SpeedrushRegular.otf"))
   { //https://www.fontspace.com/speed-rush-font-f71421 //links font
       cout << "Error while loading font" << endl;
   } // loads font

   // Sets the special font to the assigned string
   sf::Text score;
   score.setFont(font); // applies the font
   score.setString("Score: 0");
   score.setCharacterSize(60); // sets size
   score.setPosition(500, 425); // sets position



   //------------------------------------------------------- Logo/Block Background/Main Background



   // Loads in logo.png from files
   sf::Texture LogoTex;
   if(!LogoTex.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/logo.png")) {
       cout << "Could not load Tetris Logo." << endl;
       return -1;
   } // loads logo.png

   // creates an environment to apply logo.png
   sf::Sprite LogoSpr;
   LogoSpr.setTexture(LogoTex); // applies logo.png
   LogoSpr.setScale(sf::Vector2f(.3,.3)); // sets size
   LogoSpr.setPosition(sf::Vector2f(430,75)); // sets position


   // Loads in blueboxBG.jpg from files
   sf::Texture BoxTex;
   if(!BoxTex.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/blueboxBG.jpg")) {
       cout << "Could not load Box Background." << endl;
       return -1;
   }

   // creates an environment to apply blueboxBG.jpg
   sf::Sprite BoxSpr;
   BoxSpr.setTexture(BoxTex); // applies blueboxBG.jpg
   BoxSpr.setScale(sf::Vector2f(.8,.7)); // sets the rendered image size
   BoxSpr.setOrigin(0,0); // sets the origin/beginning point on the rendered blueboxBG.jpg
   BoxSpr.setPosition(sf::Vector2f(375,0));
   BoxSpr.setRotation(90); // rotates the image


   // Loads in Plane.png
   sf::Texture PlaneTex;
   if(!PlaneTex.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/Plane.png")) {
       cout << "Could not load Main Background." << endl;
       return -1;
   }

   // creates an environment to apply Plane.png
   sf::Sprite PlaneSpr;
   PlaneSpr.setTexture(PlaneTex); // applies Plane.png
   PlaneSpr.setScale(sf::Vector2f(1,1));
   PlaneSpr.setOrigin(0,0);
   PlaneSpr.setPosition(sf::Vector2f(360,0));


   //------------------------------------------------------- Loading & Rendering Sprites/Images


   // Loads border_blocks.png from files
   sf::Texture BorderBlocks;
   if(!BorderBlocks.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/border_blocks.png")) {
       cout << "Could not load Box Background." << endl;
       return -1;
   }


   // creates environment for a subdivision BorderTop1Spr of BorderBlocks
   sf::Sprite BorderTop1Spr;
   BorderTop1Spr.setTexture(BorderBlocks); // applies border_blocks.png
   BorderTop1Spr.setScale(sf::Vector2f(.3,.3));
   BorderTop1Spr.setOrigin(0,0);
   BorderTop1Spr.setPosition(sf::Vector2f(260,0));
   BorderTop1Spr.setRotation(90); // rotates image

   // creates environment for a subdivision BorderTop2Spr of BorderBlocks
   sf::Sprite BorderTop2Spr;
   BorderTop2Spr.setTexture(BorderBlocks); // apples border_blocks.png
   BorderTop2Spr.setScale(sf::Vector2f(.3,.3));
   BorderTop2Spr.setOrigin(0,0);
   BorderTop2Spr.setPosition(sf::Vector2f(380,0));
   BorderTop2Spr.setRotation(90); // rotates image

   // creates environment for a subdivision BorderLeft1Spr of BorderBlocks
   sf::Sprite BorderLeft1;
   BorderLeft1.setTexture(BorderBlocks); // applies border_blocks.png
   BorderLeft1.setScale(sf::Vector2f(.3,.3));
   BorderLeft1.setOrigin(0,0);
   BorderLeft1.setPosition(sf::Vector2f(380,280));
   BorderLeft1.setRotation(180); // rotates image

   // creates environment for a subdivision BorderLeft2Spr of BorderBlocks
   sf::Sprite BorderLeft2;
   BorderLeft2.setTexture(BorderBlocks); // applies border_blocks.png
   BorderLeft2.setScale(sf::Vector2f(.3,.3));
   BorderLeft2.setOrigin(0,0);
   BorderLeft2.setPosition(sf::Vector2f(380,540));
   BorderLeft2.setRotation(180);

   // creates environment for a subdivision BorderLeft3Spr of BorderBlocks
   sf::Sprite BorderLeft3;
   BorderLeft3.setTexture(BorderBlocks); // applies border_blocks.png
   BorderLeft3.setScale(sf::Vector2f(.3,.3));
   BorderLeft3.setOrigin(0,0);
   BorderLeft3.setPosition(sf::Vector2f(380,750));
   BorderLeft3.setRotation(180); // rotates image

   // creates environment for a subdivision BorderBottom1Spr of BorderBlocks
   sf::Sprite BorderBottom1;
   BorderBottom1.setTexture(BorderBlocks); // applies border_blocks.png
   BorderBottom1.setScale(sf::Vector2f(.3,.3));
   BorderBottom1.setOrigin(0,0);
   BorderBottom1.setPosition(sf::Vector2f(122,701));
   BorderBottom1.setRotation(270); // rotates image

   // creates environment for a subdivision BorderBottom2Spr of BorderBlocks
   sf::Sprite BorderBottom2;
   BorderBottom2.setTexture(BorderBlocks); // applies border_blocks.png
   BorderBottom2.setScale(sf::Vector2f(.3,.3));
   BorderBottom2.setOrigin(0,0);
   BorderBottom2.setPosition(sf::Vector2f(1,701));
   BorderBottom2.setRotation(270); // rotates image

   // creates environment for a subdivision BorderRight1Spr of BorderBlocks
   sf::Sprite BorderRight1;
   BorderRight1.setTexture(BorderBlocks); // applies border_blocks.png
   BorderRight1.setScale(sf::Vector2f(.3,.3));
   BorderRight1.setOrigin(0,0);
   BorderRight1.setPosition(sf::Vector2f(1,425));

   // creates environment for a subdivision BorderRight2Spr of BorderBlocks
   sf::Sprite BorderRight2;
   BorderRight2.setTexture(BorderBlocks); // applies border_blocks.png
   BorderRight2.setScale(sf::Vector2f(.3,.3));
   BorderRight2.setOrigin(0,0);
   BorderRight2.setPosition(sf::Vector2f(1,260));

   // creates environment for a subdivision BorderRight3Spr of BorderBlocks
   sf::Sprite BorderRight3;
   BorderRight3.setTexture(BorderBlocks); // applies border_blocks.png
   BorderRight3.setScale(sf::Vector2f(.3,.3));
   BorderRight3.setOrigin(0,0);
   BorderRight3.setPosition(sf::Vector2f(1,0));



   //------------------------------------------------------- Sprites

   // each point represents a corner or line intersection

   // creates 2x2 square block
   sf::RectangleShape square(sf::Vector2f(40.0f, 40.0f));
   square.setOrigin(20,20);
   square.setPosition(200,30);

   // creates 1x4 rectangle block
   sf::RectangleShape rectangle(sf::Vector2f(20.0f, 80.0f));
   rectangle.setOrigin(20,40);
   rectangle.setPosition(200,30);
   rectangle.getLocalBounds();

   // creates T block
   sf::ConvexShape tee(8);
   // as if rotated as T
   tee.setPoint(0, sf::Vector2f(0,0)); // top-top left corner
   tee.setPoint(1, sf::Vector2f(0,60)); // top-bottom left corner
   tee.setPoint(2, sf::Vector2f(20,60)); // left inner corner
   tee.setPoint(3, sf::Vector2f(20,40)); // bottom left
   tee.setPoint(4, sf::Vector2f(40,40)); // bottom right
   tee.setPoint(5, sf::Vector2f(40,20)); // right inner corner
   tee.setPoint(6, sf::Vector2f(20,20)); // top-bottom right corner
   tee.setPoint(7, sf::Vector2f(20,0)); // top-top right corner
   tee.setOrigin(20,40);
   tee.setPosition(200,30);

   // creates L block
   sf::ConvexShape el(8);
   el.setPoint(0, sf::Vector2f(0,0));
   el.setPoint(1, sf::Vector2f(0,60));
   el.setPoint(2, sf::Vector2f(40,60));
   el.setPoint(3, sf::Vector2f(40,40));
   el.setPoint(4, sf::Vector2f(21,40));
   el.setPoint(5, sf::Vector2f(20,40));
   el.setPoint(6, sf::Vector2f(20,80));
   el.setPoint(7, sf::Vector2f(20,0));
   el.setOrigin(20,40);
   el.setPosition(200,30);

   // creates reversed L block
   sf::ConvexShape el_left(8);
   el_left.setPoint(0, sf::Vector2f(40,0));
   el_left.setPoint(1, sf::Vector2f(40,60));
   el_left.setPoint(2, sf::Vector2f(0,60));
   el_left.setPoint(3, sf::Vector2f(0,40));
   el_left.setPoint(4, sf::Vector2f(21,40));
   el_left.setPoint(5, sf::Vector2f(20,40));
   el_left.setPoint(6, sf::Vector2f(20,80));
   el_left.setPoint(7, sf::Vector2f(20,0));
   el_left.setOrigin(20,40);
   el_left.setPosition(200,30);

   // creates reversed S block
   sf::ConvexShape es_right(8);
   es_right.setPoint(0, sf::Vector2f(0,0));
   es_right.setPoint(1, sf::Vector2f(0,20));
   es_right.setPoint(2, sf::Vector2f(20,20));
   es_right.setPoint(3, sf::Vector2f(20,40));
   es_right.setPoint(4, sf::Vector2f(60,40));
   es_right.setPoint(5, sf::Vector2f(60,20));
   es_right.setPoint(6, sf::Vector2f(40,20));
   es_right.setPoint(7, sf::Vector2f(40,0));
   es_right.setOrigin(20,40);
   es_right.setPosition(200,30);

   // creates S block
   sf::ConvexShape es(8);
   es.setPoint(0, sf::Vector2f(20,0));
   es.setPoint(1, sf::Vector2f(20,20));
   es.setPoint(2, sf::Vector2f(0,20));
   es.setPoint(3, sf::Vector2f(0,40));
   es.setPoint(4, sf::Vector2f(40,40));
   es.setPoint(5, sf::Vector2f(40,20));
   es.setPoint(6, sf::Vector2f(60,20));
   es.setPoint(7, sf::Vector2f(60,0));
   es.setOrigin(40,20);
   es.setPosition(200,30);

   // creates 1x1 square
   sf::RectangleShape single(sf::Vector2f(20.0f, 20.0f)); // sets pixel/boundary size
   single.setOrigin(20,40);
   single.setPosition(200,30);
   single.getLocalBounds();

   // creates 1x2 rectangle
   sf::RectangleShape small_rectangle(sf::Vector2f(20.0f, 40.0f)); // sets pixel/boundary size
   small_rectangle.setOrigin(20,40);
   small_rectangle.setPosition(200,30);
   small_rectangle.getLocalBounds();

   // creates 2x3 rectangle
   sf::RectangleShape large_rectangle(sf::Vector2f(60.0f, 40.0f)); // sets pixel/boundary size
   large_rectangle.setOrigin(20,40);
   large_rectangle.setPosition(200,30);
   large_rectangle.getLocalBounds();



   //------------------------------------------------------- Declaring cells and borders



   sf::RectangleShape cell_vertical(sf::Vector2f(1, borders_height)); // vertical thin lines in game map
   sf::RectangleShape cell_horizontal(sf::Vector2f(borders_width, 1)); // horizontal thin lines in game map

   // Top border
   sf::RectangleShape border1(sf::Vector2f(borders_width,20.0));
   border1.setPosition(1,1);

   //Bottom border
   sf::RectangleShape border2(sf::Vector2f(borders_width,20.0));
   border2.setPosition(1,borders_height-border2.getSize().y);

   // Left border
   sf::RectangleShape border3(sf::Vector2f(20.0,borders_height));
   border3.setPosition(1,1);

   // Right border
   sf::RectangleShape border4(sf::Vector2f(20.0,borders_height));
   border4.setPosition(borders_width-border4.getSize().x,1);



   //------------------------------------------------------- Declares Row Deletion Position



   sf::RectangleShape row_deletion(sf::Vector2f(1,1));
   row_deletion.setPosition(350,670); // sets the boundaries of deletion



   //------------------------------------------------------- Sets Texture/Images to the blocks



   //Textures - credit to KindPNG.com for the images

   // 2x2 square texture
   sf::Texture squaretexture;
   if (!squaretexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/square.png")) // loads square.png
       return -1;
   square.setTexture(&squaretexture);


   // 1x4 rectangle texture
   sf::Texture rectangletexture;
   if (!rectangletexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/rectangle.png"))
       return -1;
   rectangle.setTexture(&rectangletexture);


   // L texture
   sf::Texture eltexture;
   if (!eltexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/el.png"))
       return -1;
   el.setTexture(&eltexture);


   // backwards L texture
   sf::Texture el_lefttexture;
   if (!el_lefttexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/el_left.png"))
       return -1;
   el_left.setTexture(&el_lefttexture);


   // S texture
   sf::Texture estexture;
   if (!estexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/es.png"))
       return -1;
   es.setTexture(&estexture);


   // backwards S texture
   sf::Texture es_righttexture;
   if (!es_righttexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML//es_right.png"))
       return -1;
   es_right.setTexture(&es_righttexture);


   // T texture
   sf::Texture teetexture;
   if (!teetexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/tee.png"))
       return -1;
   tee.setTexture(&teetexture);


   // 1x1 square texture
   sf::Texture singletexture;
   if (!singletexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/single.png"))
       return -1;
   single.setTexture(&singletexture);


   // 1x2 rectangle texture
   sf::Texture small_rectangletexture;
   if (!small_rectangletexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/small_rectangle.png"))
       return -1;
   small_rectangle.setTexture(&small_rectangletexture);


   // 2x3 rectangle texture
   sf::Texture large_rectangletexture;
   if (!large_rectangletexture.loadFromFile("C:/Users/hoyen/CLionProjects/HelloSFML/large_rectangle.png"))
       return -1;
   large_rectangle.setTexture(&large_rectangletexture);



   //------------------------------------------------------- textures



   srand (time(NULL));
   int i = rand() % 5;
   int first = i;

   // puts shapes in to an array
   sf::Shape *shape[7]={&rectangle,&square,&single, &small_rectangle, &large_rectangle};
   sf::RectangleShape fallen_rectangle[1000];
   sf::ConvexShape fallen_convex[1000];
   sf::Shape *fallen_shape[1000];

   int t = 0;
   int scorecount = 0;
   int posx[1000];
   int posy[1000];



   //------------------------------------------------------- start of while loop (events to occur during the game)



   while (window.isOpen()) {


       sf::Event event;
       shape[i]->move(0,0.1); // (x,y)

       while(window.pollEvent(event)) {
           switch(event.type){

               case sf::Event::Closed:
                   window.close();
                   break;
               case sf::Event::KeyPressed:

                   if(event.key.code == sf::Keyboard::Escape){
                       window.close();
                   }
                   if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right){
                       shape[i]->move(20.0,0.0); // (x,y)

                       for(int k = 0; k < t; k++) { //Prevents shape from moving horizontally into other shapes

                           if(shape[i]->getGlobalBounds().intersects(fallen_shape[k]->getGlobalBounds()))
                               shape[i]->move(-20.0,0.0); // (x,y)
                       }
                       //s.move(50.0,0.0);
                   }
                   else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left){
                       shape[i]->move(-20.0,0.0); // (x,y)

                       for(int k = 0; k < t; k++) { //Prevents shape from moving horizontally into other shapes

                           if(shape[i]->getGlobalBounds().intersects(fallen_shape[k]->getGlobalBounds()))
                               shape[i]->move(20.0,0.0); // (x,y)
                       }
                       //s.move(-50.0,0.0);
                   }
                   else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down){
                       //s.move(0.0,50.0);
                       shape[i]->rotate(90); // rotates clockwise

                       for(int k = 0; k < t; k++) { //Prevents shape from rotating into other shapes

                           if(shape[i]->getGlobalBounds().intersects(fallen_shape[k]->getGlobalBounds()))
                               shape[i]->rotate(-90); // rotates counter-clockwise
                       }
                   }
                   else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up){
                       //s.move(0.0,-50.0);
                   }
                   break;
           }
       }



       //------------------------------------------------------- Correctly setting the wall borders for each shape rotation that is off



       if((i == 0 && (shape[i]->getRotation() == 90 || shape[i]->getRotation() == 270)) ||
          ((i == 2) && shape[i]->getRotation() == 270) || ((i == 3) && shape[i]->getRotation() == 270) ||
          ((i == 4) && (shape[i]->getRotation() == 180 || shape[i]->getRotation() == 270))) {

           if (i != 2) {

               // top border
               if (shape[i]->getPosition().x - 40 < border1.getSize().y) {
                   shape[i]->setPosition(border1.getSize().y + 20, shape[i]->getPosition().y);
                   shape[i]->getGlobalBounds();

                   if (shape[i]->getGlobalBounds().width >= 40) {
                       shape[i]->setPosition((border1.getSize().y + 40), shape[i]->getPosition().y);
                   } //left with some shapes (goes one over)
               }
           }
           else {

               if (shape[i]->getPosition().x - 60 < border1.getSize().y) {
                   shape[i]->setPosition(border1.getSize().y + 40, shape[i]->getPosition().y);
                   shape[i]->getGlobalBounds();

                   if (shape[i]->getGlobalBounds().width >= 40) {
                       shape[i]->setPosition((border1.getSize().y + 40), shape[i]->getPosition().y);
                   } //left with some shapes (goes one over)
               }
           }
       }
       else if((i == 0 && (shape[i]->getRotation() == 180)) || (i == 1 && (shape[i]->getRotation() == 270)) ||
               (i == 2) && shape[i]->getRotation() == 180 || ((i == 3) && (shape[i]->getRotation() == 90 || shape[i]->getRotation() == 180)) ||
               ((i == 4) && (shape[i]->getRotation() == 90))) {

           if(i == 1) {

               if (shape[i]->getPosition().x - 20 < border1.getSize().y) {
                   shape[i]->setPosition(border1.getSize().y + 20, shape[i]->getPosition().y);
                   shape[i]->getGlobalBounds();

                   if (shape[i]->getGlobalBounds().width >= 40) {
                       shape[i]->setPosition((border1.getSize().y + 40), shape[i]->getPosition().y);
                   } //left with some shapes (stops one before)
               }
           }
           else {

               if (shape[i]->getPosition().x - 0 < border1.getSize().y) {
                   shape[i]->setPosition(border1.getSize().y + 20, shape[i]->getPosition().y);
                   shape[i]->getGlobalBounds();

                   if (shape[i]->getGlobalBounds().width >= 40) {
                       shape[i]->setPosition((border1.getSize().y + 40), shape[i]->getPosition().y);
                   } //left with some shapes (stops one before)
               }
           }
       }
       else if((i == 2) && shape[i]->getRotation() == 90) {

           if (shape[i]->getPosition().x + 20 < border1.getSize().y) {
               shape[i]->setPosition(border1.getSize().y, shape[i]->getPosition().y);
               shape[i]->getGlobalBounds();

               if (shape[i]->getGlobalBounds().width >= 40) {
                   shape[i]->setPosition((border1.getSize().y + 40), shape[i]->getPosition().y);
               } //left with some shapes (stops two before)
           }
       }
       else {

           if (shape[i]->getPosition().x - 20 < border1.getSize().y) {
               shape[i]->setPosition(border1.getSize().y + 20, shape[i]->getPosition().y);
               shape[i]->getGlobalBounds();

               if (shape[i]->getGlobalBounds().width >= 40) {
                   shape[i]->setPosition((border1.getSize().y + 40), shape[i]->getPosition().y);
               }
           }
           //left for all others
       }



       //------------------------------------------------------- Correcting borders and bounds



       if((i == 3 && shape[i]->getRotation() == 270) || (i == 2 && shape[i]->getRotation() == 270)) {

           if (shape[i]->getPosition().x + shape[i]->getGlobalBounds().width-40> window_width-border4.getSize().x-520){
               shape[i]->setPosition(window_width-border4.getSize().x -
               shape[i]->getGlobalBounds().width - 520, shape[i]->getPosition().y);
           } //right with some shapes (stops two before)
       }

       else if((i == 0 && (shape[i]->getRotation() == 90 || shape[i]->getRotation() == 270)) ||
               ((i == 4) && shape[i]->getRotation() == 180) || shape[i]->getRotation() == 270) {

           if (shape[i]->getPosition().x + shape[i]->getGlobalBounds().width-40> window_width-border4.getSize().x-520){
               shape[i]->setPosition(window_width-border4.getSize().x -
               shape[i]->getGlobalBounds().width - 520, shape[i]->getPosition().y);
           } //right with some shapes (stops one before)
       }

       else if((i == 0 && (shape[i]->getRotation() == 180)) || ((i == 2) && shape[i]->getRotation() == 180) ||
               ((i == 3) && (shape[i]->getRotation() == 90 || shape[i]->getRotation() == 180))
               | (i == 4) && shape[i]->getRotation() == 90) {

           if (shape[i]->getPosition().x + shape[i]->getGlobalBounds().width - 0 >
               window_width - border4.getSize().x-520) {
               shape[i]->setPosition(window_width - border4.getSize().x - shape[i]->getGlobalBounds().width - 520,
                                     shape[i]->getPosition().y);
               //right with some shapes (goes one over)
           }
       }

       else if((i == 2) && shape[i]->getRotation() == 90) {

           if (shape[i]->getPosition().x + shape[i]->getGlobalBounds().width + 40 >
               window_width - border4.getSize().x-520) {
               shape[i]->setPosition(window_width - border4.getSize().x - shape[i]->getGlobalBounds().width - 540,
                                     shape[i]->getPosition().y);
               //right with some shapes (goes two over)
           }
       }

       else {

           if (shape[i]->getPosition().x + shape[i]->getGlobalBounds().width - 20 >
               window_width - border4.getSize().x-520) {
               shape[i]->setPosition(window_width - border4.getSize().x - shape[i]->getGlobalBounds().width - 520,
                                     shape[i]->getPosition().y);
           }
           //right for all others
       }

       if (shape[i]->getPosition().y < border3.getSize().x-520) {
           shape[i]->setPosition(shape[i]->getPosition().x - 520, border3.getSize().x);
       }



       //-------------------------------------------------------  Assigns Color Values to the objects creates



       //Coloring and drawing shapes/text
       window.clear();
       border1.setFillColor(sf::Color::Black);
       border2.setFillColor(sf::Color::Black);
       border3.setFillColor(sf::Color::Black);
       border4.setFillColor(sf::Color::Black);
       score.setFillColor(sf::Color::White);
       cell_vertical.setFillColor(sf::Color(85, 85, 85));
       cell_horizontal.setFillColor(sf::Color(85, 85, 85));

       window.draw(BoxSpr); // prints the blueboxBG.png
       // must be printed first so cells can be visible on top



       //------------------------------------------------------- Cell creation


       // setting size and quantity of cells
       for (int c = 1; c < 19; c++) {
           cell_vertical.setPosition(20 * c, 1);
           window.draw(cell_vertical);
       }
       for (int r = 1; r < 35; r++) {
           cell_horizontal.setPosition(1, 20 * r);
           window.draw(cell_horizontal);
       }



       //------------------------------------------------------- Printing



       window.draw(border1); // draws the colored borders
       window.draw(border2);
       window.draw(border3);
       window.draw(border4);
       window.draw(PlaneSpr); // draws the main background
       window.draw(*shape[i]); // draws the different shapes
       window.draw(BorderRight1); // draws the block borders
       window.draw(BorderRight2);
       window.draw(BorderRight3);
       window.draw(BorderLeft1);
       window.draw(BorderLeft2);
       window.draw(BorderLeft3);
       window.draw(BorderTop1Spr);
       window.draw(BorderTop2Spr);
       window.draw(BorderBottom1);
       window.draw(BorderBottom2);
       window.draw(score); // draws the score string with the font
       window.draw(LogoSpr); // draws the logo



       //------------------------------------------------------- Collision Code


       if (shape[i]->getGlobalBounds().intersects(border2.getGlobalBounds())) { //Collisions with bottom border

           switch (i) {
               case 0:
                   fallen_rectangle[t] = rectangle;
                   fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                   fallen_shape[t] = &fallen_rectangle[t];
                   break;
               case 1:
                   fallen_rectangle[t] = square;
                   fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                   fallen_shape[t] = &fallen_rectangle[t];
                   break;
               case 2:
                   fallen_rectangle[t] = single;
                   fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                   fallen_shape[t] = &fallen_rectangle[t];
                   break;
               case 3:
                   fallen_rectangle[t] = small_rectangle;
                   fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                   fallen_shape[t] = &fallen_rectangle[t];
                   break;
               case 4:
                   fallen_rectangle[t] = large_rectangle;
                   fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                   fallen_shape[t] = &fallen_rectangle[t];
                   break;
           }



           //------------------------------------------------------- Operates Key movements for corrected rotations


           // randomly generate and drop shapes
           if (i > 5) {

               i = rand() % 5;
               shape[i]->setPosition(200, 30);
               window.draw(*shape[i]);
           }
           else {

               shape[i]->setPosition(200, 30);
               window.draw(*shape[i]);
               i = rand() % 5;
           }


           shape[i]->move(0, 0.1);
           sf::Event event2;

           while (window.pollEvent(event2)) {

               switch (event2.type) {
                   case sf::Event::Closed:
                       window.close();
                       break;
                   case sf::Event::KeyPressed:

                       if (event2.key.code == sf::Keyboard::Escape) {
                           window.close();
                       }
                       if (event.key.code == sf::Keyboard::D){
                           shape[i]->move(20.0,0.0);

                           for(int k = 0; k < t; k++) { //Prevents shape from moving horizontally into other shapes

                               if(shape[i]->getGlobalBounds().intersects(fallen_shape[k]->getGlobalBounds()))
                                   shape[i]->move(-20.0,0.0);
                           }
                           //s.move(50.0,0.0);
                       }
                       else if (event.key.code == sf::Keyboard::A){

                           shape[i]->move(-20.0,0.0);

                           for(int k = 0; k < t; k++) { //Prevents shape from moving horizontally into other shapes

                               if(shape[i]->getGlobalBounds().intersects(fallen_shape[k]->getGlobalBounds()))
                                   shape[i]->move(20.0,0.0);
                           }
                           //s.move(-50.0,0.0);
                       }
                       else if (event.key.code == sf::Keyboard::S){
                           //s.move(0.0,50.0);

                           shape[i]->rotate(90);

                           for(int k = 0; k < t; k++) { //Prevents shape from rotating into other shapes

                               if(shape[i]->getGlobalBounds().intersects(fallen_shape[k]->getGlobalBounds()))
                                   shape[i]->rotate(-90);
                           }
                       }
                       else if (event.key.code == sf::Keyboard::W){
                           //s.move(0.0,-50.0);
                       }
                       break;
               }
           }
           t++;



           //------------------------------------------------------- Row detection code



           for (int c = 30; c <= 670; c = c + 20) { //Detects if a row is filled.
               // If it is, it deletes all shapes whose centers are on or above the row.

               int count = 0;
               int blocks[1000];
               int b = 0;

               for (int r = 30; r <= 350; r = r + 20) {
                   row_deletion.setPosition(r, c);

                   for (int l = 0; l < t; l++) {

                       if (row_deletion.getGlobalBounds().intersects(fallen_shape[l]->getGlobalBounds())) {
                           count++;
                       }
                   }
               }
               if (count == 17) {

                   for(int h = 0; h < t; h++) {

                       if(fallen_shape[h]->getPosition().y <= (c + 30))
                           fallen_shape[h]->setPosition(fallen_shape[h]->getPosition().x,
                                                        fallen_shape[h]->getPosition().y + 800);
                   }

                   string new_score = "Score: " + to_string(++scorecount); //Increments score and changes string in text accordingly
                   score.setString(new_score); // displays and increments the score variable
               }
           }
       }



       //------------------------------------------------------- Block Tracking



       for(int k = 0; k < t; k++) { //Collisions with other blocks
           if (shape[i]->getGlobalBounds().intersects(fallen_shape[k]->getGlobalBounds())) {

               int posx = (int)shape[i]->getPosition().x;
               int posy = (int)shape[i]->getPosition().y;

               // prints the origin location and the falling location
               cout << "Shape x: " << shape[i]->getPosition().x << endl;
               cout << "Shape y: " << shape[i]->getPosition().y << endl;
               cout << "Fallen Shape x: " << fallen_shape[k]->getPosition().x<< endl;
               cout << "Fallen Shape y: " << fallen_shape[k]->getPosition().y<< endl << t << endl << endl;
               cout << shape[i]->getRotation();

               // tracks the position of the falling shape
               switch (i) {

                   case 0:
                       fallen_rectangle[t] = rectangle;
                       fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                       fallen_shape[t] = &fallen_rectangle[t];
                       break;
                   case 1:
                       fallen_rectangle[t] = square;
                       fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                       fallen_shape[t] = &fallen_rectangle[t];
                       break;
                   case 2:
                       fallen_rectangle[t] = single;
                       fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                       fallen_shape[t] = &fallen_rectangle[t];
                       break;
                   case 3:
                       fallen_rectangle[t] = small_rectangle;
                       fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                       fallen_shape[t] = &fallen_rectangle[t];
                       break;
                   case 4:
                       fallen_rectangle[t] = large_rectangle;
                       fallen_rectangle[t].setPosition(shape[i]->getPosition().x, shape[i]->getPosition().y);
                       fallen_shape[t] = &fallen_rectangle[t];
                       break;
               }


               //------------------------------------------------------- Game Over
               // Closes the game if maximum height is reached
               if(fallen_shape[k]->getPosition().y < 40)
                   window.close();
               if (i > 5) {

                   i = rand() % 5;
                   shape[i]->setPosition(200, 30);
                   window.draw(*shape[i]);
               } else {

                   shape[i]->setPosition(200, 30);
                   window.draw(*shape[i]);
                   i = rand() % 5;
               }


               //------------------------------------------------------- Key Movements

               shape[i]->move(0, 0.1);
               sf::Event event2;

               while (window.pollEvent(event2)) {
                   switch (event2.type) {

                       case sf::Event::Closed:
                           window.close();
                           break;
                       case sf::Event::KeyPressed:
                           if (event2.key.code == sf::Keyboard::Escape) {
                               window.close();
                           }
                           if (event2.key.code == sf::Keyboard::D || event2.key.code == sf::Keyboard::Right) {
                               shape[i]->move(20.0, 0.0); // (x,y)
                               //s.move(50.0,0.0);
                           } else if (event2.key.code == sf::Keyboard::A || event2.key.code == sf::Keyboard::Left) {
                               shape[i]->move(-20.0, 0.0); // (x,y)
                               //s.move(-50.0,0.0);
                           } else if (event2.key.code == sf::Keyboard::S || event2.key.code == sf::Keyboard::Down) {
                               //s.move(0.0,50.0);
                               shape[i]->rotate(90); // rotates shape
                           } else if (event2.key.code == sf::Keyboard::W || event2.key.code == sf::Keyboard::Up) {
                               //s.move(0.0,-50.0);
                           }
                           break;
                   }
               }
               t++;

           }
       }


       //------------------------------------------------------- Prints the falling shapes


       for(int j = 0; j < t; j++)
       {
           window.draw(*fallen_shape[j]);
       }
       window.display();

   }

   return 0;
   }