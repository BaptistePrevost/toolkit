#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

namespace TOOLKIT {

    class EventCallbackBase {
        public:
        virtual ~EventCallbackBase() = default;
        virtual void tryProcess(sf::Event const& event_raw) const = 0;
    };
    
    template <typename TEvent>
    class EventCallback final : public EventCallbackBase {
        public:
        EventCallback(std::function<void(TEvent const&)> callback) : callback_{std::move(callback)} {}

        void tryProcess(sf::Event const& event_raw) const override final {
            auto const* event = event_raw.getIf<TEvent>();
            if (event) callback_(*event);
        }

        private:
        std::function<void(const TEvent&)> callback_{nullptr};
        
    };
}