#ifndef DIRECTORIES_H
#define DIRECTORIES_H

#define DIR_LOGS std::string("logs/")
#define DIR_DATA std::string("data/")
#define DIR_GRAPHICS DIR_DATA + std::string("graphics/")
#define DIR_SHADERS DIR_GRAPHICS + std::string("shaders/")
#define DIR_MESHES DIR_GRAPHICS + std::string("meshes/")
#define DIR_MATERIALS DIR_GRAPHICS + std::string("materials/")
#define DIR_SOUNDS DIR_DATA + std::string("sounds/")
#define DIR_PHYSICS DIR_DATA + std::string("physics/")
#define DIR_WORLD DIR_DATA + std::string("world/")
#define DIR_SAVES std::string("saves/")
#define DIR_SETTINGS std::string("settings/")

#define EXT_WORLD std::string(".world")
#define EXT_LOG std::string(".log")
#define EXT_SHADER_LIST std::string(".slst")
#define EXT_PROGRAM_LIST std::string(".plst")
#define EXT_MESH_LIST std::string(".mlst")
#define EXT_ENTITY_LIST std::string(".elst")
#define EXT_ENTITY_DEFINITION std::string(".edef")
#define EXT_VERTEX_SHADER std::string(".vert")
#define EXT_FRAGMENT_SHADER std::string(".frag")
#define EXT_GEOMETRY_SHADER std::string(".geom")
#define EXT_TESS_CONTROL_SHADER std::string(".tesc")
#define EXT_TESS_EVALUATION_SHADER std::string(".tese")
#define EXT_MESH std::string(".obj")
#define EXT_MATERIAL std::string(".mtl")

#define FILE_LOG std::string("log") + EXT_LOG
#define FILE_SHADER_LIST DIR_GRAPHICS + std::string("shaders") + EXT_SHADER_LIST
#define FILE_PROGRAM_LIST DIR_GRAPHICS + std::string("programs") + EXT_PROGRAM_LIST
#define FILE_MESH_LIST DIR_GRAPHICS + std::string("meshes") + EXT_MESH_LIST
#define FILE_ENITITY_LIST DIR_WORLD + std::string("entities") + EXT_ENTITY_LIST
#define FILE_ENTITY_DEFINITION DIR_WORLD + std::string("entities") + EXT_ENTITY_DEFINITION

#endif // DIRECTORIES_H
