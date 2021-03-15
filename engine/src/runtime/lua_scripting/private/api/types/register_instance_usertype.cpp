#include "data_model/elements/instance.hpp"
#include "lua_scripting/api/types/instance_usertypes.hpp"
#include "lua_scripting/data_model/make_instance_as_lua.hpp"
#include "lua_scripting/data_model/to_lua_object.hpp"

using namespace openworld;

void openworld::register_instance_usertype(std::shared_ptr<lua_execution_context> execution_context)
{
    auto& lua = execution_context->state();
    auto instance_manager = execution_context->instance_manager();

    auto lua_usertype = lua.new_usertype<instance>(instance::ClassName);

    lua_usertype[sol::meta_function::construct] =
        sol::factories(
            [=](sol::this_state s, const std::string& className)
            {
                return make_instance_as_lua(s, instance_manager, className);
            },
            [=](sol::this_state s, const std::string& className, instance* parent)
            {
                return make_instance_as_lua(s, instance_manager, className, parent);
            },
            [=](sol::this_state s, const std::string& className, const sol::table& properties)
            {
                return make_instance_as_lua(s, instance_manager, className, properties);
            }
        );

    lua_usertype["ClassName"] =
        sol::readonly_property(&instance::class_name);

    lua_usertype["Name"] =
        sol::property(
            &instance::get_name,
            &instance::set_name);

    lua_usertype["Parent"] =
        sol::property(
            [](instance* this_inst, sol::this_state s)
            {
                return to_lua_object(s, this_inst->get_parent());
            },
            [](instance* this_inst, instance* new_parent)
            {
                if (new_parent == nullptr)
                {
                    this_inst->set_parent(nullptr);
                    return;
                }

                this_inst->set_parent(new_parent->shared_from_this());
            });

    lua_usertype["GetFullName"] =
        &instance::get_full_name;

    lua_usertype["GetChildren"] =
        [](instance* this_inst, sol::this_state s)
    {
        auto children = this_inst->get_children();

        std::vector<sol::object> lua_children;
        lua_children.resize(children.size());

        std::transform(children.begin(),
            children.end(),
            lua_children.begin(),
            [&](std::shared_ptr<instance> child) { return to_lua_object(s, child); });

        return lua_children;
    };

    lua_usertype["IsAncestorOf"] =
        &instance::is_ancestor_of;

    lua_usertype["IsDescendantOf"] =
        &instance::is_descendant_of;

    lua_usertype["ClearAllChildren"] =
        &instance::clear_all_children;

    lua_usertype["Destroy"] =
        &instance::destroy;
}