#include <utility>
#include <any>

#include "data_model/management/instance_factory.hpp"

class client_lighting_service final :
    public openworld::base_lighting_service
{
};

class client_scheduler_service final :
    public openworld::base_scheduler_service
{
public:
    virtual bool is_client() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual bool is_server() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual bool is_editor() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual bool is_running() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual void run() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual void stop() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual void pause() override
    {
        throw std::runtime_error("not implemented");
    }

};

class client_world_service final :
    public openworld::base_world_service
{
};

int main()
{

    auto lighting_service = std::make_shared<client_lighting_service>();
    auto scheduler_service = std::make_shared<client_scheduler_service>();
    auto world_service = std::make_shared<client_world_service>();

    auto instance_factory =
        std::make_shared<openworld::instance_factory>(
            lighting_service,
            scheduler_service,
            world_service);




    auto data_model = instance_factory->create<openworld::data_model>();
    auto c1 = data_model->child_added().connect(
        [](openworld::instance_ptr<openworld::instance> ptr)
        {
            return;
        });
    auto c2 = data_model->child_removed().connect(
        [](openworld::instance_ptr<openworld::instance> ptr)
        {
            return;
        });

    auto scheduler = instance_factory->create<openworld::scheduler>();
    scheduler->set_parent(openworld::static_instance_cast<openworld::instance>(data_model));

    auto world = instance_factory->create<openworld::world>();
    world->set_parent(openworld::static_instance_cast<openworld::instance>(data_model));

    openworld::instance_ptr<openworld::sky> sky;
    {
        auto lighting = instance_factory->create<openworld::lighting>();
        lighting->set_parent(openworld::static_instance_cast<openworld::instance>(data_model));

        {
            sky = instance_factory->create<openworld::sky>();
            sky->set_parent(openworld::static_instance_cast<openworld::instance>(lighting));
        }
    }

    return 0;
}
