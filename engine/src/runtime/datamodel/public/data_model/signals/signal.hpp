#pragma once

namespace openworld
{
    class signal_connection;

    template <typename T>
    class signal;

    template <class RetT, class... ArgsT>
    class signal<RetT(ArgsT...)>
    {
    public:
        template <typename CallbackT>
        signal_connection connect(CallbackT callback, int order = 0)
        {
            return {};
        }

        template <typename CallbackT>
        bool disconnect(CallbackT callback)
        {
            return false;
        }

        bool disconnect_all()
        {
            return false;
        }

        void dispatch(ArgsT... args) const
        {
            return;
        }
    };
}