#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=App/Main.c Hall/Button/Hall_Button_prog.c Hall/DC_Motor/Hall_Dc_Motor_prog.c Hall/Key_Pad/Hall_Key_Pad_prog.c Hall/LCD/Hall_lcd_prog.c Hall/Led/Hall_Led_prog.c Hall/Relay/Hall_Relay_prog.c Hall/Seven_seg/Hall_Seven_seg_prog.c Hall/Hall_dfs.c Mcal/Mcal_ADC/Mcal_ADC_prog.c Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.c Mcal/Mcal_GPIO/Mcal_GPIO_prog.c Mcal/Mcal_interrupt/Mcal_external_interrupt.c Mcal/Mcal_interrupt/Mcal_interrupt_manager.c Mcal/Mcal_interrupt/Mcal_internal_interrupt.c Mcal/Mcal_Device_cfg.c Mcal/Mcal_dfs.c Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.c App/ISR.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/App/Main.p1 ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1 ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1 ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1 ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1 ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1 ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1 ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1 ${OBJECTDIR}/Hall/Hall_dfs.p1 ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1 ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1 ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1 ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1 ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1 ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1 ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1 ${OBJECTDIR}/Mcal/Mcal_dfs.p1 ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1 ${OBJECTDIR}/App/ISR.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/App/Main.p1.d ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1.d ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1.d ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1.d ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1.d ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1.d ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1.d ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1.d ${OBJECTDIR}/Hall/Hall_dfs.p1.d ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1.d ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1.d ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1.d ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1.d ${OBJECTDIR}/Mcal/Mcal_dfs.p1.d ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1.d ${OBJECTDIR}/App/ISR.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/App/Main.p1 ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1 ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1 ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1 ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1 ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1 ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1 ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1 ${OBJECTDIR}/Hall/Hall_dfs.p1 ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1 ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1 ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1 ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1 ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1 ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1 ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1 ${OBJECTDIR}/Mcal/Mcal_dfs.p1 ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1 ${OBJECTDIR}/App/ISR.p1

# Source Files
SOURCEFILES=App/Main.c Hall/Button/Hall_Button_prog.c Hall/DC_Motor/Hall_Dc_Motor_prog.c Hall/Key_Pad/Hall_Key_Pad_prog.c Hall/LCD/Hall_lcd_prog.c Hall/Led/Hall_Led_prog.c Hall/Relay/Hall_Relay_prog.c Hall/Seven_seg/Hall_Seven_seg_prog.c Hall/Hall_dfs.c Mcal/Mcal_ADC/Mcal_ADC_prog.c Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.c Mcal/Mcal_GPIO/Mcal_GPIO_prog.c Mcal/Mcal_interrupt/Mcal_external_interrupt.c Mcal/Mcal_interrupt/Mcal_interrupt_manager.c Mcal/Mcal_interrupt/Mcal_internal_interrupt.c Mcal/Mcal_Device_cfg.c Mcal/Mcal_dfs.c Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.c App/ISR.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/App/Main.p1: App/Main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/App" 
	@${RM} ${OBJECTDIR}/App/Main.p1.d 
	@${RM} ${OBJECTDIR}/App/Main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/App/Main.p1 App/Main.c 
	@-${MV} ${OBJECTDIR}/App/Main.d ${OBJECTDIR}/App/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/App/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1: Hall/Button/Hall_Button_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Button" 
	@${RM} ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1 Hall/Button/Hall_Button_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Button/Hall_Button_prog.d ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1: Hall/DC_Motor/Hall_Dc_Motor_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/DC_Motor" 
	@${RM} ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1 Hall/DC_Motor/Hall_Dc_Motor_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.d ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1: Hall/Key_Pad/Hall_Key_Pad_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Key_Pad" 
	@${RM} ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1 Hall/Key_Pad/Hall_Key_Pad_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.d ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1: Hall/LCD/Hall_lcd_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/LCD" 
	@${RM} ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1 Hall/LCD/Hall_lcd_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.d ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1: Hall/Led/Hall_Led_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Led" 
	@${RM} ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1 Hall/Led/Hall_Led_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Led/Hall_Led_prog.d ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1: Hall/Relay/Hall_Relay_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Relay" 
	@${RM} ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1 Hall/Relay/Hall_Relay_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.d ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1: Hall/Seven_seg/Hall_Seven_seg_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Seven_seg" 
	@${RM} ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1 Hall/Seven_seg/Hall_Seven_seg_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.d ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Hall_dfs.p1: Hall/Hall_dfs.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall" 
	@${RM} ${OBJECTDIR}/Hall/Hall_dfs.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Hall_dfs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Hall_dfs.p1 Hall/Hall_dfs.c 
	@-${MV} ${OBJECTDIR}/Hall/Hall_dfs.d ${OBJECTDIR}/Hall/Hall_dfs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Hall_dfs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1: Mcal/Mcal_ADC/Mcal_ADC_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_ADC" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1 Mcal/Mcal_ADC/Mcal_ADC_prog.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.d ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1: Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_EEPROM" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1 Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.d ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1: Mcal/Mcal_GPIO/Mcal_GPIO_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_GPIO" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1 Mcal/Mcal_GPIO/Mcal_GPIO_prog.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.d ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1: Mcal/Mcal_interrupt/Mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_interrupt" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1 Mcal/Mcal_interrupt/Mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1: Mcal/Mcal_interrupt/Mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_interrupt" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1 Mcal/Mcal_interrupt/Mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1: Mcal/Mcal_interrupt/Mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_interrupt" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1 Mcal/Mcal_interrupt/Mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1: Mcal/Mcal_Device_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1 Mcal/Mcal_Device_cfg.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_Device_cfg.d ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_dfs.p1: Mcal/Mcal_dfs.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_dfs.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_dfs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_dfs.p1 Mcal/Mcal_dfs.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_dfs.d ${OBJECTDIR}/Mcal/Mcal_dfs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_dfs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1: Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_Timer_0" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1 Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.d ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/App/ISR.p1: App/ISR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/App" 
	@${RM} ${OBJECTDIR}/App/ISR.p1.d 
	@${RM} ${OBJECTDIR}/App/ISR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/App/ISR.p1 App/ISR.c 
	@-${MV} ${OBJECTDIR}/App/ISR.d ${OBJECTDIR}/App/ISR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/App/ISR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/App/Main.p1: App/Main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/App" 
	@${RM} ${OBJECTDIR}/App/Main.p1.d 
	@${RM} ${OBJECTDIR}/App/Main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/App/Main.p1 App/Main.c 
	@-${MV} ${OBJECTDIR}/App/Main.d ${OBJECTDIR}/App/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/App/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1: Hall/Button/Hall_Button_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Button" 
	@${RM} ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1 Hall/Button/Hall_Button_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Button/Hall_Button_prog.d ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Button/Hall_Button_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1: Hall/DC_Motor/Hall_Dc_Motor_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/DC_Motor" 
	@${RM} ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1 Hall/DC_Motor/Hall_Dc_Motor_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.d ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/DC_Motor/Hall_Dc_Motor_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1: Hall/Key_Pad/Hall_Key_Pad_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Key_Pad" 
	@${RM} ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1 Hall/Key_Pad/Hall_Key_Pad_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.d ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Key_Pad/Hall_Key_Pad_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1: Hall/LCD/Hall_lcd_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/LCD" 
	@${RM} ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1 Hall/LCD/Hall_lcd_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.d ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/LCD/Hall_lcd_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1: Hall/Led/Hall_Led_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Led" 
	@${RM} ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1 Hall/Led/Hall_Led_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Led/Hall_Led_prog.d ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Led/Hall_Led_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1: Hall/Relay/Hall_Relay_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Relay" 
	@${RM} ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1 Hall/Relay/Hall_Relay_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.d ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Relay/Hall_Relay_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1: Hall/Seven_seg/Hall_Seven_seg_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall/Seven_seg" 
	@${RM} ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1 Hall/Seven_seg/Hall_Seven_seg_prog.c 
	@-${MV} ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.d ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Seven_seg/Hall_Seven_seg_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Hall/Hall_dfs.p1: Hall/Hall_dfs.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Hall" 
	@${RM} ${OBJECTDIR}/Hall/Hall_dfs.p1.d 
	@${RM} ${OBJECTDIR}/Hall/Hall_dfs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Hall/Hall_dfs.p1 Hall/Hall_dfs.c 
	@-${MV} ${OBJECTDIR}/Hall/Hall_dfs.d ${OBJECTDIR}/Hall/Hall_dfs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Hall/Hall_dfs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1: Mcal/Mcal_ADC/Mcal_ADC_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_ADC" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1 Mcal/Mcal_ADC/Mcal_ADC_prog.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.d ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_ADC/Mcal_ADC_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1: Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_EEPROM" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1 Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.d ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_EEPROM/Mcal_EEPROM_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1: Mcal/Mcal_GPIO/Mcal_GPIO_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_GPIO" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1 Mcal/Mcal_GPIO/Mcal_GPIO_prog.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.d ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_GPIO/Mcal_GPIO_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1: Mcal/Mcal_interrupt/Mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_interrupt" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1 Mcal/Mcal_interrupt/Mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1: Mcal/Mcal_interrupt/Mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_interrupt" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1 Mcal/Mcal_interrupt/Mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1: Mcal/Mcal_interrupt/Mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_interrupt" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1 Mcal/Mcal_interrupt/Mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.d ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_interrupt/Mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1: Mcal/Mcal_Device_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1 Mcal/Mcal_Device_cfg.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_Device_cfg.d ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_Device_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_dfs.p1: Mcal/Mcal_dfs.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_dfs.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_dfs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_dfs.p1 Mcal/Mcal_dfs.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_dfs.d ${OBJECTDIR}/Mcal/Mcal_dfs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_dfs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1: Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal/Mcal_Timer_0" 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1.d 
	@${RM} ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1 Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.c 
	@-${MV} ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.d ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal/Mcal_Timer_0/Mcal_Timer_0_prog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/App/ISR.p1: App/ISR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/App" 
	@${RM} ${OBJECTDIR}/App/ISR.p1.d 
	@${RM} ${OBJECTDIR}/App/ISR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/App/ISR.p1 App/ISR.c 
	@-${MV} ${OBJECTDIR}/App/ISR.d ${OBJECTDIR}/App/ISR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/App/ISR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/pic18f4620.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/pic18f4620.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/pic18f4620.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/pic18f4620.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/pic18f4620.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/pic18f4620.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
