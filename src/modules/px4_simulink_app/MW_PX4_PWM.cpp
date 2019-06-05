/* Copyright 2018 The MathWorks, Inc. */

#include "nuttxinitialize.h"
#include "MW_PX4_TaskControl.h"
#include "MW_PX4_PWM.h"

#ifndef MW_PWM_MAIN_ONESHOT
#define MW_PWM_MAIN_ONESHOT 0
#endif

#ifndef MW_PWM_MAIN_FREQUENCY
#define MW_PWM_MAIN_FREQUENCY 0
#endif

#ifndef MW_PWM_AUX_ONESHOT
#define MW_PWM_AUX_ONESHOT 0
#endif

#ifndef MW_PWM_AUX_FREQUENCY
#define MW_PWM_AUX_FREQUENCY 0
#endif

#ifndef MW_PWM_CH1_FAILSAFE
#define MW_PWM_CH1_FAILSAFE 0
#endif

#ifndef MW_PWM_CH1_DISARMED
#define MW_PWM_CH1_DISARMED 0
#endif

#ifndef MW_PWM_CH2_FAILSAFE
#define MW_PWM_CH2_FAILSAFE 0
#endif

#ifndef MW_PWM_CH2_DISARMED
#define MW_PWM_CH2_DISARMED 0
#endif

#ifndef MW_PWM_CH3_FAILSAFE
#define MW_PWM_CH3_FAILSAFE 0
#endif

#ifndef MW_PWM_CH3_DISARMED
#define MW_PWM_CH3_DISARMED 0
#endif

#ifndef MW_PWM_CH4_FAILSAFE
#define MW_PWM_CH4_FAILSAFE 0
#endif

#ifndef MW_PWM_CH4_DISARMED
#define MW_PWM_CH4_DISARMED 0
#endif

#ifndef MW_PWM_CH5_FAILSAFE
#define MW_PWM_CH5_FAILSAFE 0
#endif

#ifndef MW_PWM_CH5_DISARMED
#define MW_PWM_CH5_DISARMED 0
#endif

#ifndef MW_PWM_CH6_FAILSAFE
#define MW_PWM_CH6_FAILSAFE 0
#endif

#ifndef MW_PWM_CH6_DISARMED
#define MW_PWM_CH6_DISARMED 0
#endif

#ifndef MW_PWM_CH7_FAILSAFE
#define MW_PWM_CH7_FAILSAFE 0
#endif

#ifndef MW_PWM_CH7_DISARMED
#define MW_PWM_CH7_DISARMED 0
#endif

#ifndef MW_PWM_CH8_FAILSAFE
#define MW_PWM_CH8_FAILSAFE 0
#endif

#ifndef MW_PWM_CH8_DISARMED
#define MW_PWM_CH8_DISARMED 0
#endif

#ifndef MW_PWM_AUX_CH1_FAILSAFE
#define MW_PWM_AUX_CH1_FAILSAFE 0
#endif

#ifndef MW_PWM_AUX_CH1_DISARMED
#define MW_PWM_AUX_CH1_DISARMED 0
#endif

#ifndef MW_PWM_AUX_CH2_FAILSAFE
#define MW_PWM_AUX_CH2_FAILSAFE 0
#endif

#ifndef MW_PWM_AUX_CH2_DISARMED
#define MW_PWM_AUX_CH2_DISARMED 0
#endif

#ifndef MW_PWM_AUX_CH3_FAILSAFE
#define MW_PWM_AUX_CH3_FAILSAFE 0
#endif

#ifndef MW_PWM_AUX_CH3_DISARMED
#define MW_PWM_AUX_CH3_DISARMED 0
#endif

#ifndef MW_PWM_AUX_CH4_FAILSAFE
#define MW_PWM_AUX_CH4_FAILSAFE 0
#endif

#ifndef MW_PWM_AUX_CH4_DISARMED
#define MW_PWM_AUX_CH4_DISARMED 0
#endif

#ifndef MW_PWM_AUX_CH5_FAILSAFE
#define MW_PWM_AUX_CH5_FAILSAFE 0
#endif

#ifndef MW_PWM_AUX_CH5_DISARMED
#define MW_PWM_AUX_CH5_DISARMED 0
#endif

#ifndef MW_PWM_AUX_CH6_FAILSAFE
#define MW_PWM_AUX_CH6_FAILSAFE 0
#endif

#ifndef MW_PWM_AUX_CH6_DISARMED
#define MW_PWM_AUX_CH6_DISARMED 0
#endif

#ifndef MW_PWM_AUX_CH7_FAILSAFE
#define MW_PWM_AUX_CH7_FAILSAFE 0
#endif

#ifndef MW_PWM_AUX_CH7_DISARMED
#define MW_PWM_AUX_CH7_DISARMED 0
#endif

#ifndef MW_PWM_AUX_CH8_FAILSAFE
#define MW_PWM_AUX_CH8_FAILSAFE 0
#endif

#ifndef MW_PWM_AUX_CH8_DISARMED
#define MW_PWM_AUX_CH8_DISARMED 0
#endif

#define DEBUG 0

#define PWM_SUCCESS 0
#define PWM_OPEN_FAIL 1
#define PWM_SERVOCOUNT_FAIL 2
#define PWM_ARM_FAIL 4
#define PWM_DISARM_FAIL 8
#define PWM_SETRATE_FAIL 16
#define PWM_SETCHANNEL_FAIL 32
#define PWM_SETFS_FAIL 64
#define PWM_SETDA_FAIL 128
#define PWM_FORCEFS_FAIL 256
#define PWM_FORCETERMFS_FAIL 512
#define PWM_SETSERVO_FAIL 1024
#define PWM_RESETSERVO_FAIL 2048
#define PWM_CLOSE_FAIL 4096

unsigned pwm_open(int* pwmHandler, const char* pwmDevice) {
    int fd = px4_open(pwmDevice, 0);

    if (fd < 0) {
        PX4_ERR("can't open %s", pwmDevice);
        return PWM_OPEN_FAIL;
    }
    *pwmHandler = fd;

    PX4_INFO("* Opened PWM Device: %s (fd = %d)*\n", pwmDevice, *pwmHandler);
    return PWM_SUCCESS;
}

unsigned pwm_getServoCount(const int* pwmHandler, unsigned* servoCount) {
    /* get the number of servo channels */
    unsigned servo_count;
    int fd = *pwmHandler;
    int ret = px4_ioctl(fd, PWM_SERVO_GET_COUNT, (unsigned long)&servo_count);

    if (ret != OK) {
#if DEBUG
        PX4_ERR("PWM_SERVO_GET_COUNT");
#endif
        return PWM_SERVOCOUNT_FAIL;
    }
#if DEBUG
    PX4_INFO("Number of servo channels is %d", servo_count);
#endif

    *servoCount = servo_count;
    return PWM_SUCCESS;
}

unsigned pwm_arm(const int* pwmHandler) {
    /* tell safety that its ok to disable it with the switch */
    int fd = *pwmHandler;
    int ret = px4_ioctl(fd, PWM_SERVO_SET_ARM_OK, 0);

    if (ret != OK) {
#if DEBUG
        err(1, "PWM_SERVO_SET_ARM_OK");
#endif
    }

    /* tell IO that the system is armed (it will output values if safety is off) */
    ret = px4_ioctl(fd, PWM_SERVO_ARM, 0);

    if (ret != OK) {
#if DEBUG
        err(1, "PWM_SERVO_ARM");
#endif
        return PWM_ARM_FAIL;
    }

    return PWM_SUCCESS;
}

unsigned pwm_disarm(const int* pwmHandler) {
    /* disarm, but do not revoke the SET_ARM_OK flag */
    int fd = *pwmHandler;
    int ret = px4_ioctl(fd, PWM_SERVO_DISARM, 0);

    if (ret != OK) {
#if DEBUG
        err(1, "PWM_SERVO_DISARM");
#endif
        return PWM_DISARM_FAIL;
    }
    return PWM_SUCCESS;
}

unsigned pwm_setPWMRate(const int* pwmHandler, boolean_T isMain) {
    /* Change alternate PWM rate or set oneshot
     * Either the "oneshot" command was used
     * OR rate was provided, so we will issue the
     * PWM_SERVO_SET_UPDATE_RATE ioctl
     */
    int rate = 0;
    int fd = *pwmHandler;
    if (isMain) {
#if defined(MW_PWM_MAIN_ONESHOT) && (MW_PWM_MAIN_ONESHOT == 1)
        rate = 0; /*Set rate as 0 for oneshot*/
#else
        rate = MW_PWM_MAIN_FREQUENCY;
#endif
    } else {
#if defined(MW_PWM_AUX_ONESHOT) && (MW_PWM_AUX_ONESHOT == 1)
        rate = 0; /*Set rate as 0 for oneshot*/
#else
        rate = MW_PWM_AUX_FREQUENCY;
#endif
    }
#if DEBUG
    PX4_INFO("Frequency %d:", rate);
#endif

    int ret = px4_ioctl(fd, PWM_SERVO_SET_UPDATE_RATE, rate);

    if (ret != OK) {

#if DEBUG
        PX4_ERR("PWM_SERVO_SET_UPDATE_RATE (check rate for sanity)");
#endif
        return PWM_SETRATE_FAIL;
    }

    return PWM_SUCCESS;
}

unsigned pwm_setChannelMask(const int* pwmHandler, int channelMask) {
    int fd = *pwmHandler;
    int ret = px4_ioctl(fd, PWM_SERVO_SET_SELECT_UPDATE_RATE, channelMask);

    if (ret != OK) {
#if DEBUG
        PX4_ERR("PWM_SERVO_SET_SELECT_UPDATE_RATE");
#endif
        return PWM_SETCHANNEL_FAIL;
    }
    return PWM_SUCCESS;
}

unsigned pwm_setDisarmedPWM(const int* pwmHandler,
                            unsigned servo_count,
                            int channelMask,
                            boolean_T isMain) {
    struct pwm_output_values pwm_values;

    memset(&pwm_values, 0, sizeof(pwm_values));

    pwm_values.channel_count = servo_count;

    /* first get current state before modifying it */
    int fd = *pwmHandler;
    int ret = px4_ioctl(fd, PWM_SERVO_GET_DISARMED_PWM, (long unsigned int)&pwm_values);

    if (ret != OK) {
#if DEBUG
        PX4_ERR("failed get disarmed values");
#endif
    }

    int pwmValue[8];
    getDAPWMValues(isMain, pwmValue);

    for (unsigned i = 0; i < servo_count; i++) {
        if (channelMask & 1 << i) {
            pwm_values.values[i] = pwmValue[i];
        }
    }

    ret = px4_ioctl(fd, PWM_SERVO_SET_DISARMED_PWM, (long unsigned int)&pwm_values);

    if (ret != OK) {
#if DEBUG
        PX4_ERR("failed setting disarmed values (%d)", ret);
#endif
        return PWM_SETDA_FAIL;
    }

    return PWM_SUCCESS;
}

unsigned pwm_setFailsafePWM(const int* pwmHandler,
                            unsigned servo_count,
                            int channelMask,
                            boolean_T isMain) {
    struct pwm_output_values pwm_values;

    memset(&pwm_values, 0, sizeof(pwm_values));

    pwm_values.channel_count = servo_count;

    /* first get current state before modifying it */
    int fd = *pwmHandler;
    int ret = px4_ioctl(fd, PWM_SERVO_GET_FAILSAFE_PWM, (long unsigned int)&pwm_values);

    if (ret != OK) {
#if DEBUG
        PX4_ERR("failed get failsafe values");
#endif
    }

    int pwmValue[8];
    getFSPWMValues(isMain, pwmValue);

    for (unsigned i = 0; i < servo_count; i++) {
        if (channelMask & 1 << i) {
            pwm_values.values[i] = pwmValue[i];
        }
    }

    ret = px4_ioctl(fd, PWM_SERVO_SET_FAILSAFE_PWM, (long unsigned int)&pwm_values);

    if (ret != OK) {
#if DEBUG
        PX4_ERR("failed setting failsafe values (%d)", ret);
#endif
        return PWM_SETFS_FAIL;
    }

    return PWM_SUCCESS;
}

unsigned pwm_forceFailsafe(const int* pwmHandler, int value) {
    /*force failsafe: 1 - on, 0 - off*/
    int fd = *pwmHandler;
    int ret = px4_ioctl(fd, PWM_SERVO_SET_FORCE_FAILSAFE, value);
    if (ret != OK) {
#if DEBUG
        PX4_ERR("FAILED setting forcefail");
#endif
        return PWM_FORCEFS_FAIL;
    }

    return PWM_SUCCESS;
}

unsigned pwm_forceTerminateFailsafe(const int* pwmHandler, int value) {
    /*force terminate failsafe: 1 - on, 0 - off*/
    int fd = *pwmHandler;
    int ret = px4_ioctl(fd, PWM_SERVO_SET_TERMINATION_FAILSAFE, value);
    if (ret != OK) {
#if DEBUG
        PX4_ERR("FAILED setting termination forcefail");
#endif
        return PWM_FORCETERMFS_FAIL;
    }

    return PWM_SUCCESS;
}

unsigned pwm_setServo(const int* pwmHandler,
                      unsigned servo_count,
                      int channelMask,
                      uint16_t* pwm_value) {
    int fd = *pwmHandler;
    int ret;
    for (unsigned i = 0; i < servo_count; i++) {
        if (channelMask & 1 << i) {
            ret = px4_ioctl(fd, PWM_SERVO_SET(i), pwm_value[i]);

            if (ret != OK) {
#if DEBUG
                PX4_ERR("PWM_SERVO_SET(%d)", i);
#endif
                return PWM_SETSERVO_FAIL;
            }
        }
    }

    /* Delay longer than the max Oneshot duration */

    usleep(2542);

#ifdef __PX4_NUTTX
    /* Trigger all timer's channels in Oneshot mode to fire
     * the oneshots with updated values.
     */

    up_pwm_update();
#endif

    return PWM_SUCCESS;
}

unsigned pwm_resetServo(const int* pwmHandler,
                        unsigned servo_count,
                        int channelMask,
                        boolean_T isMain) {
    int fd = *pwmHandler;
    int ret;

    int pwmValue[8];
    getDAPWMValues(isMain, pwmValue);

    for (unsigned i = 0; i < servo_count; i++) {
        if (channelMask & 1 << i) {
            ret = px4_ioctl(fd, PWM_SERVO_SET(i), pwmValue[i]);

            if (ret != OK) {
#if DEBUG
                PX4_ERR("PWM_SERVO_SET(%d)", i);
#endif
                return PWM_RESETSERVO_FAIL;
            }
        }
    }

    return PWM_SUCCESS;
}

unsigned pwm_close(const int* pwmHandler) {
    int fd = *pwmHandler;
    /** clear the 'ARM ok' bit, which deactivates the safety switch */
    px4_ioctl(fd, PWM_SERVO_CLEAR_ARM_OK, 0);
    px4_close(fd);

    return PWM_SUCCESS;
}

void getFSPWMValues(boolean_T isMain, int* fsPWMvalues) {

    for (int index = 0; index < 8; index++) {
        if (isMain) {
            switch (index) {
            case 0:
                fsPWMvalues[index] = MW_PWM_CH1_FAILSAFE;
                break;
            case 1:
                fsPWMvalues[index] = MW_PWM_CH2_FAILSAFE;
                break;
            case 2:
                fsPWMvalues[index] = MW_PWM_CH3_FAILSAFE;
                break;
            case 3:
                fsPWMvalues[index] = MW_PWM_CH4_FAILSAFE;
                break;
            case 4:
                fsPWMvalues[index] = MW_PWM_CH5_FAILSAFE;
                break;
            case 5:
                fsPWMvalues[index] = MW_PWM_CH6_FAILSAFE;
                break;
            case 6:
                fsPWMvalues[index] = MW_PWM_CH7_FAILSAFE;
                break;
            case 7:
                fsPWMvalues[index] = MW_PWM_CH8_FAILSAFE;
                break;
            }
        } else {
            switch (index) {
            case 0:
                fsPWMvalues[index] = MW_PWM_AUX_CH1_FAILSAFE;
                break;
            case 1:
                fsPWMvalues[index] = MW_PWM_AUX_CH2_FAILSAFE;
                break;
            case 2:
                fsPWMvalues[index] = MW_PWM_AUX_CH3_FAILSAFE;
                break;
            case 3:
                fsPWMvalues[index] = MW_PWM_AUX_CH4_FAILSAFE;
                break;
            case 4:
                fsPWMvalues[index] = MW_PWM_AUX_CH5_FAILSAFE;
                break;
            case 5:
                fsPWMvalues[index] = MW_PWM_AUX_CH6_FAILSAFE;
                break;
            case 6:
                fsPWMvalues[index] = MW_PWM_AUX_CH7_FAILSAFE;
                break;
            case 7:
                fsPWMvalues[index] = MW_PWM_AUX_CH8_FAILSAFE;
                break;
            }
        }
    }
}

void getDAPWMValues(boolean_T isMain, int* daPWMvalues) {

    for (int index = 0; index < 8; index++) {
        if (isMain) {
            switch (index) {
            case 0:
                daPWMvalues[index] = MW_PWM_CH1_DISARMED;
                break;
            case 1:
                daPWMvalues[index] = MW_PWM_CH2_DISARMED;
                break;
            case 2:
                daPWMvalues[index] = MW_PWM_CH3_DISARMED;
                break;
            case 3:
                daPWMvalues[index] = MW_PWM_CH4_DISARMED;
                break;
            case 4:
                daPWMvalues[index] = MW_PWM_CH5_DISARMED;
                break;
            case 5:
                daPWMvalues[index] = MW_PWM_CH6_DISARMED;
                break;
            case 6:
                daPWMvalues[index] = MW_PWM_CH7_DISARMED;
                break;
            case 7:
                daPWMvalues[index] = MW_PWM_CH8_DISARMED;
                break;
            }
        } else {
            switch (index) {
            case 0:
                daPWMvalues[index] = MW_PWM_AUX_CH1_DISARMED;
                break;
            case 1:
                daPWMvalues[index] = MW_PWM_AUX_CH2_DISARMED;
                break;
            case 2:
                daPWMvalues[index] = MW_PWM_AUX_CH3_DISARMED;
                break;
            case 3:
                daPWMvalues[index] = MW_PWM_AUX_CH4_DISARMED;
                break;
            case 4:
                daPWMvalues[index] = MW_PWM_AUX_CH5_DISARMED;
                break;
            case 5:
                daPWMvalues[index] = MW_PWM_AUX_CH6_DISARMED;
                break;
            case 6:
                daPWMvalues[index] = MW_PWM_AUX_CH7_DISARMED;
                break;
            case 7:
                daPWMvalues[index] = MW_PWM_AUX_CH8_DISARMED;
                break;
            }
        }
    }
}
