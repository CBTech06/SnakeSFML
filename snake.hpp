/* copyright (c) 2017 bourgeois christophe
permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "software"), to deal
in the software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the software, and to permit persons to whom the software is
furnished to do so, subject to the following conditions:
the above copyright notice and this permission notice shall be included in all
copies or substantial portions of the software.
the software is provided "as is", without warranty of any kind, express or
implied, including but not limited to the warranties of merchantability,
fitness for a particular purpose and noninfringement. in no event shall the
authors or copyright holders be liable for any claim, damages or other
lIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.#include "boat.hpp"
*/

#ifndef _SNAKE_
#define _SNAKE_

#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "pills.hpp"

#define TILE_SIZE 16
enum dir{NONE,UP,DOWN,LEFT,RIGHT};


class Pills;

class Snake
{
public:
  Snake();
  sf::Vector2f move();
  void updatePosition();
  inline const int returnSnakeParts() { return parts;} 
  inline const sf::Vector2f getPosition() { return position; }
  void eatPills(const sf::Vector2f&,Pills&,float& );
  void moveTail(const sf::Vector2f&);
  void checkTreeCollision(const std::vector<sf::FloatRect>&);
  void checkCollision(const sf::Vector2f&,const int&);
  void draw(sf::RenderWindow&);
private:
  int parts;
  int direction;
  int collision;
  int speed;
  int oldParts;
  const int window_x;
  const int window_y;
  const int window_width;
  const int window_height;
  sf::Vector2f position;
  sf::Sprite sprite;
  sf::Texture texture;
  
};

#endif
