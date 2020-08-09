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

#ifndef _BOARD_
#define _BOARD_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <sstream>

enum {WALKABLE,UNWALKABLE};

class Board{
public:
  Board();
  std::vector<int>& load();
  void show(sf::RenderWindow &);
  std::vector<sf::FloatRect> collisionInfo();
private:
  int tileSize;
  std::vector<int> map;
  std::vector<sf::FloatRect> blocks;
  int width;
  int height;
  sf::Texture tileSet;
  int tileX;
  int tileY;
  sf::Sprite tile;
};

#endif

