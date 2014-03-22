#include "Common.h"

#include "Logger.h"
#include "Game.h"

class Entity : public Drawable,
               public KeyListener,
               public MouseListener {
public:
    Entity() = default;

    Entity(Camera *const &camera,
           Mesh *const &mesh,
           Texture *const &texture,
           Material *const &material,
           GLMatrix4 *const &transform) :
        Drawable(mesh,
                 texture,
                 material,
                 transform),
        camera(camera) {
            InputManager::getCurrentInstance()->addKeyListener(this);
            InputManager::getCurrentInstance()->addMouseListener(this);
        }

    void render() const {
        getMesh()->render();
    }

    void keyPressed(KeyEvent *const &e) {

    }

    void keyTyped(CharEvent *const &e) {
        std::cout << static_cast<char>(e->key) << std::endl;
    }

    void mouseButtonPressed(MouseButtonEvent *const &e) {

    }

    void mouseCursorEntered(MouseEnterEvent *const &e) {

    }

    void mouseCursorMoved(MouseMotionEvent *const &e) {

    }

    void mouseWheelScrolled(MouseScrollEvent *const &e) {
        camera->translate(GLVector3(0, 0, -1),
                          e->yoffset / 100.0f);

        //std::cout << *camera << std::endl;
    }

private:
    Camera *camera;

public:
    Camera *const &getCamera() const {
        return camera;
    }

    void setCamera(Camera *const &camera) {
        this->camera = camera;
    }
};

int main() {
    //Engine::init("saves/test/logs/log.log");
    Logger *logger = Logger::createInstance();
    logger->open("saves/test/logs/log.log");

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

    TextureCache *textures = new TextureCache("data/graphics/textures/");

    MaterialCache *materials = new MaterialCache("data/graphics/materials/");

    Camera *camera = new Camera(0.5f,
                                100.0f,
                                75.0f,
                                static_cast<float>(width) / static_cast<float>(height));

    GLMatrix4 *transform = new GLMatrix4 {1, 0, 0, 0,
                                         0, 1, 0, 0,
                                         0, 0, 1, 0,
                                         0, 0, -5, 1};

    //Entity *cube = new Entity(camera,
      //                        meshes->get("cube.obj"),
        //                      textures->get("flowers.jpg"),
          //                    materials->get("cube.mat"),
           //                   transform);

    Entity *sphere = new Entity(camera,
                                meshes->get("sphere.obj"),
                                textures->get("flowers.jpg"),
                                materials->get("cube.mat"),
                                transform);

    GraphicsManager *graphics = new GraphicsManager(window,
                                                    shaderPrograms,
                                                    meshes,
                                                    textures,
                                                    materials,
                                                    camera);
    graphics->setActiveShaderProgram("basic");

    engine->setGraphicsManager(graphics);

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
        glfwSwapBuffers(window);
    }

    delete engine;
    delete graphics;
    delete input;
    delete meshes;
    delete shaderPrograms;
    delete materials;
    delete textures;
    //delete cube;
    delete sphere;
    delete camera;
    delete transform;

    Logger::destroy();

    glfwTerminate();

    return 0;
}
