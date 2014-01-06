#ifndef DIRECTORIES_H
#define DIRECTORIES_H

#define DIR_LOGS "logs/"
#define DIR_DATA "data/"
#define DIR_GRAPHICS DIR_DATA + "graphics/"
#define DIR_SHADERS DIR_GRAPHICS + "shaders/"
#define DIR_MESHES DIR_GRAPHICS + "meshes/"
#define DIR_MATERIALS DIR_GRAPHICS + "materials/"
#define DIR_PHYSICS DIR_DATA + "physics/"
#define DIR_SAVES "saves/"
#define DIR_SETTINGS "settings/"

#define EXT_WORLD ".world"
#define EXT_LOG ".log"
#define EXT_SHADER_LIST ".slst"
#define EXT_PROGRAM_LIST ".plst"
#define EXT_MESH_LIST ".mlst"
#define EXT_VERTEX_SHADER ".vert"
#define EXT_FRAGMENT_SHADER ".frag"
#define EXT_GEOMETRY_SHADER ".geom"
#define EXT_TESS_CONTROL_SHADER ".tesc"
#define EXT_TESS_EVALUATION_SHADER ".tese"
#define EXT_MESH ".obj"
#define EXT_MATERIAL ".mtl"
#define EXT_ENTITY ".ent"

#define FILE_LOG "log" + EXT_LOG
#define FILE_SHADER_LIST DIR_GRAPHICS + "shaders" + EXT_SHADER_LIST
#define FILE_PROGRAM_LIST DIR_GRPAHICS + "programs" + EXT_PROGRAM_LIST
#define FILE_MESH_LIST DIR_GRAPHICS + "meshes" + EXT_MESH_LIST

#endif // DIRECTORIES_H
