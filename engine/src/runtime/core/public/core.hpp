#pragma once

#include <cstdint>
#include <cmath>
#include <cassert>
#include <typeinfo>
#include <typeindex>
#include <type_traits>
#include <stdexcept>
#include <initializer_list>
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>
#include <span>
#include <optional>
#include <atomic>
#include <mutex>
#include <thread>
#include <utility>
#include <algorithm>

#include "core/signals/signal.hpp"

#include "core/utilities/enums.hpp"
#include "core/utilities/hash.hpp"
#include "core/utilities/macros.hpp"

#include "core/engine/exceptions.hpp"
#include "core/engine/service_locator.hpp"
#include "core/engine/engine.hpp"

#include "core/containers/memory_region.hpp"

#include "core/logging/enums.hpp"

#include "core/platform/window.hpp"
#include "core/platform/impl/application_host_impl.hpp"
#include "core/platform/platform_system.hpp"
#include "core/platform/application_host.hpp"

#include "core/platform/win32/win32_api.hpp"
#include "core/platform/win32/win32_window.hpp"
#include "core/platform/win32/win32_application_host_impl.hpp"
#include "core/platform/win32/win32_platform_system.hpp"