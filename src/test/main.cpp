#include "Common.h"

#include "Logger.h"
#include "Game.h"
#include "Actor.h"
#include "Entity.h"

int main() {
    //Engine::init("saves/test/logs/log.log");
    Logger *logger = Logger::createInstance();
    logger->open("saves/test/logs/log.log");

    //Engine engine("data/configurations/engine.xml");

    Engine *engine = Engine::createInstance("data/configurations/engine.xml");

    Entity *entity = new Entity(engine->getMesh("sphere.obj"),
                                new Texture(
                                    engine->getImage("metal.jpg")), /// implement TextureCache
                                engine->getMaterial("cube.mat"),
                                new GLMatrix4{1, 0, 0, 0,
                                              0, 1, 0, 0,
                                              0, 0, 1, 0,
                                              0, 0, 0, 1});

    Actor *actor = new Actor();

    engine->setCamera(actor);

    engine->setActiveShaderProgram("basic");

    while (!engine->isCloseRequested()) {
        engine->pollEvents();
        engine->render(entity);
        actor->update();
        engine->update();
    }

    Engine::destroy();
    Logger::destroy();
/*
    Engine *engine = new Engine(800, 800, "Demo", nullptr, nullptr);
    GLFWwindow *window = engine->getWindow();

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    InputManager *input = new InputManager(window);
    engine->setInputManager(input);

    ShaderProgramCache *shaderPrograms =
        new ShaderProgramCache("data/graphics/shaders/",
                               "data/graphics/shaders/programs.xml");

    MeshCache *meshes = new MeshCache("data/graphics/meshes/");

    ImageCache *images = new ImageCache("data/graphics/images/");

    MaterialCache *materials = new MaterialCache("data/graphics/materials/");

    Camera *camera = new Camera(0.5f,
                                100.0f,
                                75.0f,
                                static_cast<float>(width) / static_cast<float>(height));

    camera->setPosition({0, 0, 5});

    Actor *actor = new Actor();
    actor->setCamera(camera);

    GLMatrix4 *transform = new GLMatrix4 {1, 0, 0, 0,
                                         0, 1, 0, 0,
                                         0, 0, 1, 0,
                                         0, 0, -5, 1};

    Texture *texture = new Texture(images->get("woodsample.jpg"));

    //Entity *cube = new Entity(camera,
      //                        meshes->get("cube.obj"),
        //                      images->get("flowers.jpg"),
          //                    materials->get("cube.mat"),
           //                   transform);

    Entity *sphere = new Entity(meshes->get("sphere.obj"),
                                texture,
                                materials->get("cube.mat"),
                                transform);

    GraphicsManager *graphics = new GraphicsManager(window,
                                                    shaderPrograms,
                                                    meshes,
                                                    images,
                                                    materials,
                                                    camera);
    graphics->setActiveShaderProgram("basic");

    engine->setGraphicsManager(graphics);

    glfwIconifyWindow(window);
    glfwRestoreWindow(window);

    while (!glfwWindowShouldClose(window)) {
        ASSERT(window,
               "'window' member is null.");
        ASSERT(graphics,
               "'graphics' member is null.");
        ASSERT(input,
               "'input' member is null.");

        input->process();
        //graphics->render(cube);
        graphics->render(sphere);
        actor->update();

        glfwSwapBuffers(window);
    }

    delete engine;
    delete graphics;
    delete input;
    delete meshes;
    delete shaderPrograms;
    delete materials;
    delete images;
    delete texture;
    //delete cube;
    delete sphere;
    delete actor;
    delete camera;
    delete transform;

    Logger::destroy();

    glfwTerminate();
*/
    return 0;
}
