#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

//SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;

//assets paths
#define IMG "Game/assets/img/"
#define FONT "Game/assets/font/"
#define SFX "Game/assets/sfx/"

//macros
#define ATQ_LONGO 1
#define ATQ_CURTO 2