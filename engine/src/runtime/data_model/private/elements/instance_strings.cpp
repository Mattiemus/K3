#include "data_model/elements/base_script.hpp"
#include "data_model/elements/client_script.hpp"
#include "data_model/elements/data_model.hpp"
#include "data_model/elements/folder.hpp"
#include "data_model/elements/instance.hpp"
#include "data_model/elements/lighting.hpp"
#include "data_model/elements/scheduler.hpp"
#include "data_model/elements/service_provider.hpp"
#include "data_model/elements/sky.hpp"
#include "data_model/elements/world.hpp"

const std::string openworld::base_script::ClassName = "BaseScript";
const std::string openworld::base_script::LanguageProperty = "Language";
const std::string openworld::base_script::SourceProperty = "Source";

const std::string openworld::client_script::ClassName = "ClientScript";

const std::string openworld::data_model::ClassName = "DataModel";

const std::string openworld::folder::ClassName = "Folder";

const std::string openworld::instance::ClassName = "Instance";
const std::string openworld::instance::ClassNameProperty = "ClassName";
const std::string openworld::instance::NameProperty = "Name";
const std::string openworld::instance::ParentProperty = "Parent";

const std::string openworld::lighting::ClassName = "Lighting";

const std::string openworld::scheduler::ClassName = "Scheduler";

const std::string openworld::service_provider::ClassName = "ServiceProvider";

const std::string openworld::sky::ClassName = "Sky";
const std::string openworld::sky::SkyboxTopProperty = "SkyboxTop";
const std::string openworld::sky::SkyboxBottomProperty = "SkyboxBottom";
const std::string openworld::sky::SkyboxLeftProperty = "SkyboxLeft";
const std::string openworld::sky::SkyboxRightProperty = "SkyboxRight";
const std::string openworld::sky::SkyboxFrontProperty = "SkyboxFront";
const std::string openworld::sky::SkyboxBackProperty = "SkyboxBack";

const std::string openworld::world::ClassName = "World";
