//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_USERAGENTCLASSIFIER_H
#define YAUAACPP_USERAGENTCLASSIFIER_H

#include "yauaacpp_def.h"

namespace ycpp {

    class UserAgentClassifier {
    private UserAgentClassifier(){} // Utility class

    public static DeviceClass getDeviceClass(UserAgent userAgent) {
            switch (userAgent.getValue(DEVICE_CLASS)) {
                case "Desktop":                return DESKTOP;
                case "Anonymized":             return ANONYMIZED;
                case "Mobile":                 return MOBILE;
                case "Tablet":                 return TABLET;
                case "Phone":                  return PHONE;
                case "Watch":                  return WATCH;
                case "Virtual Reality":        return VIRTUAL_REALITY;
                case "eReader":                return E_READER;
                case "Set-top box":            return SET_TOP_BOX;
                case "TV":                     return TV;
                case "Game Console":           return GAME_CONSOLE;
                case "Handheld Game Console":  return HANDHELD_GAME_CONSOLE;
                case "Robot":                  return ROBOT;
                case "Robot Mobile":           return ROBOT_MOBILE;
                case "Robot Imitator":         return ROBOT_IMITATOR;
                case "Hacker":                 return HACKER;
                case "Unknown":                return UNKNOWN;
                default:                       return UNCLASSIFIED;
            }
        }

        /**
         * @param userAgent The instance that needs to be classified.
         * @return Is this a 'normal' consumer device that can simply be bought/downloaded and used as intended.
         */
    public static bool isNormalConsumerDevice(UserAgent userAgent) {
            switch (getDeviceClass(userAgent)) {
                case DESKTOP:
                case MOBILE:
                case TABLET:
                case PHONE:
                case WATCH:
                case VIRTUAL_REALITY:
                case E_READER:
                case SET_TOP_BOX:
                case TV:
                case GAME_CONSOLE:
                case HANDHELD_GAME_CONSOLE:
                    return true;

                case ANONYMIZED:
                case ROBOT:
                case ROBOT_MOBILE:
                case ROBOT_IMITATOR:
                case HACKER:
                case UNKNOWN:
                case UNCLASSIFIED:
                default:
                    return false;
            }
        }

        /**
         * @param userAgent The instance that needs to be classified.
         * @return Is this a 'mobile' device. (includes robots that want to be treated as mobile)
         */
    public static bool isMobile(UserAgent userAgent) {
            switch (getDeviceClass(userAgent)) {
                case MOBILE:
                case TABLET:
                case PHONE:
                case WATCH:
                case VIRTUAL_REALITY:
                case E_READER:
                case HANDHELD_GAME_CONSOLE:
                case ROBOT_MOBILE:
                    return true;

                case DESKTOP:
                case SET_TOP_BOX:
                case TV:
                case GAME_CONSOLE:
                case ANONYMIZED:
                case ROBOT:
                case ROBOT_IMITATOR:
                case HACKER:
                case UNKNOWN:
                case UNCLASSIFIED:
                default:
                    return false;
            }
        }

        /**
         * @param userAgent The instance that needs to be classified.
         * @return If this is probably a human using the device.
         */
    public static bool isHuman(UserAgent userAgent) {
            switch (getDeviceClass(userAgent)) {
                case DESKTOP:
                case MOBILE:
                case TABLET:
                case PHONE:
                case WATCH:
                case VIRTUAL_REALITY:
                case E_READER:
                case SET_TOP_BOX:
                case TV:
                case GAME_CONSOLE:
                case HANDHELD_GAME_CONSOLE:
                case ANONYMIZED:
                    return true;

                case ROBOT:
                case ROBOT_MOBILE:
                case ROBOT_IMITATOR:
                case HACKER:
                case UNKNOWN:
                case UNCLASSIFIED:
                default:
                    return false;
            }
        }

        /**
         * @param userAgent The instance that needs to be classified.
         * @return Do we see this as deliberate misuse?
         */
    public static bool isDeliberateMisuse(UserAgent userAgent) {
            switch (getDeviceClass(userAgent)) {
                case ANONYMIZED:
                case ROBOT_IMITATOR:
                case HACKER:
                    return true;

                case DESKTOP:
                case MOBILE:
                case TABLET:
                case PHONE:
                case WATCH:
                case VIRTUAL_REALITY:
                case E_READER:
                case SET_TOP_BOX:
                case TV:
                case GAME_CONSOLE:
                case HANDHELD_GAME_CONSOLE:
                case ROBOT:
                case ROBOT_MOBILE:
                case UNKNOWN:
                case UNCLASSIFIED:
                default:
                    return false;
            }
        }

    };
}
#endif //YAUAACPP_USERAGENTCLASSIFIER_H
