//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_DEVICECLASS_H
#define YAUAACPP_DEVICECLASS_H

#include "yauaacpp_def.h"

namespace ycpp {

    public enum DeviceClass {
        /**
         * The device is assessed as a Desktop/Laptop class device.
         */
                DESKTOP("Desktop"),
        /**
         * In some cases the useragent has been altered by anonimization software.
         */
                ANONYMIZED("Anonymized"),
        /**
         * A device that is mobile yet we do not know if it is a eReader/Tablet/Phone or Watch.
         */
                MOBILE("Mobile"),
        /**
         * A mobile device with a rather large screen (common &gt; 7").
         */
                TABLET("Tablet"),
        /**
         * A mobile device with a small screen (common &lt; 7").
         */
                PHONE("Phone"),
        /**
         * A mobile device with a tiny screen (common &lt; 2"). Normally these are an additional screen for a phone/tablet type device.
         */
                WATCH("Watch"),
        /**
         * A mobile device with a VR capabilities.
         */
                VIRTUAL_REALITY("Virtual Reality"),
        /**
         * Similar to a Tablet yet in most cases with an eInk screen.
         */
                E_READER("eReader"),
        /**
         * A connected device that allows interacting via a TV sized screen.
         */
                SET_TOP_BOX("Set-top box"),
        /**
         * Similar to Set-top box yet here this is built into the TV.
         */
                TV("TV"),
        /**
         * 'Fixed' game systems like the PlayStation and XBox.
         */
                GAME_CONSOLE("Game Console"),
        /**
         * 'Mobile' game systems like the 3DS.
         */
                HANDHELD_GAME_CONSOLE("Handheld Game Console"),
        /**
         * Robots that visit the site.
         */
                ROBOT("Robot"),
        /**
         * Robots that visit the site indicating they want to be seen as a Mobile visitor.
         */
                ROBOT_MOBILE("Robot Mobile"),
        /**
         * Robots that visit the site pretending they are robots like google, but they are not.
         */
                ROBOT_IMITATOR("Robot Imitator"),
        /**
         * In case scripting is detected in the useragent string, also fallback in really broken situations.
         */
                HACKER("Hacker"),
        /**
         * We really don't know, these are usually useragents that look normal yet contain almost no information about the device.
         */
                UNKNOWN("Unknown"),
        /**
         * We found a deviceclass string that we have no enum value for.
         */
                UNCLASSIFIED("Unclassified");

        private std::string value;

        DeviceClass(const std::string & newValue) {
            value = newValue;
        }

        public std::string getValue() {
            return value;
        }
    };

}
#endif //YAUAACPP_DEVICECLASS_H
