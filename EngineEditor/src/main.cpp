#include <iostream>
#include <memory>
#include <EngineCore/Application.hpp>

class MyApp : public GraphicsEngine::Application {
    public:
    virtual void on_update() override {
        //std::cout << "Update frame: " << frame++ << std::endl;
    }

    private:
    int frame = 0;
};

int main(){
    auto myApp = std::make_unique<MyApp>();

    int returnCode = myApp->start(1024, 768, "My app");
    
    std::cin.get();

    return 0;
}