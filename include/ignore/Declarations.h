#ifndef DECLARATIONS_H
#define DECLARATIONS_H

class Camera;
class Entity;
class GLException;
class GLEWException;
class GLFWException;
class IOException;
class NullPointerException;
class Game;
class Graphics;
class Keyboard;
class Logger;
class Mesh;
class Mouse;
class Physics;
class ResourceManager;
class ShaderProgram;
struct Vertex;
struct vec2;
struct vec3;
class WindowListener;
class World;

using KeyAction = std::string;
using Key = unsigned;
using KeyMap = std::unordered_map<KeyAction, Key>;
using KeyPair = std::pair<KeyAction, Key>;

using Shader = std::pair<GLuint, GLenum>;
using ShaderMap = std::unordered_map<std::string, Shader>;
using ProgramMap = std::unordered_map<std::string, ShaderProgram*>;
using ProgramPair = std::pair<std::string, ShaderProgram*>;
using MeshMap = std::unordered_map<std::string, Mesh*>;
using MeshPair = std::pair<std::string, Mesh*>;
using EntityMap = std::unordered_map<std::string, Entity*>;
using EntityPair = std::pair<std::string, Entity*>;

#endif // DECLARATIONS_H
