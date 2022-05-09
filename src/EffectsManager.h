#pragma once
#include <Arduino.h>
#define ARDUINOJSON_ENABLE_PROGMEM 1
#include <ArduinoJson.h>
#include <vector>

#define effectsManager EffectsManager::instance()

class Effect;
class EffectsManager
{
public:
    static EffectsManager *instance();
    static void Initialize();

    void loop();

    void processEffectSettings(const JsonObject &json);
    void processAllEffects();

    void next();
    void previous();
    void changeEffectByName(const String &name);
    void changeEffectById(const String &id);
    void activateEffect(uint8_t index, bool save = true);

    void updateCurrentSettings(const JsonObject &json);
    void updateSettingsById(const String &id, const JsonObject &json);

    uint8_t count();

    Effect *activeEffect();
    uint8_t activeEffectIndex();

    std::vector<Effect*> effects = {};

protected:
    EffectsManager();
};

