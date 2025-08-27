#pragma once

#include <functional>

namespace TOOLKIT {

    template<typename TKey, typename TEvent>
    class EventCategoryHandler {
        public:
        using CallbackEvent = std::function<void(TEvent)>;
        using CallbackKey = std::function<TKey(TEvent const&)>;

        private:
        std::unordered_map<TKey, CallbackEvent> maps_;
        CallbackKey key_extractor_;

        public:
        explicit EventCategoryHandler(CallbackKey key_extractor) : key_extractor_{std::move(key_extractor)} {}

        void setEventCallback(TKey key, CallbackEvent callback) {
            maps_[key] = std::move(callback);
        }

        void handle(TEvent const& event) {
            auto const it{maps_.find(key_extractor_(event))};
            if (it != maps_.end()) {
                it->second(event);
            }
        }
    };
}