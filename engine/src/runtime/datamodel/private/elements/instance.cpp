#include "data_model/elements/instance.hpp"
#include "data_model/management/instance_manager.hpp"

const std::string openworld::instance::ClassName = "Instance";
const std::string openworld::instance::ClassNameProperty = "ClassName";
const std::string openworld::instance::NameProperty = "Name";
const std::string openworld::instance::ParentProperty = "Parent";

void openworld::instance::destroy()
{
    if (m_is_destroyed)
    {
        return;
    }

    set_parent(nullptr);
    clear_all_children();

    // TODO: Should we clear signals here?

    m_is_destroyed = true;

    m_instance_manager->on_instance_destroyed(shared_from_this());
}