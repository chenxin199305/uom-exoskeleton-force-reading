/*
 * matlab_crutches.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "matlab_crutches".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon Jan 20 15:41:10 2020
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "matlab_crutches.h"
#include "matlab_crutches_private.h"
#include "matlab_crutches_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  115200.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  1.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/Serial_Port", 3U, 8, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_matlab_crutches_T matlab_crutches_B;

/* Block states (default storage) */
DW_matlab_crutches_T matlab_crutches_DW;

/* Real-time model */
RT_MODEL_matlab_crutches_T matlab_crutches_M_;
RT_MODEL_matlab_crutches_T *const matlab_crutches_M = &matlab_crutches_M_;

/* Model output function */
void matlab_crutches_output(void)
{
  /* S-Function (sldrtpi): '<Root>/Packet Input' */
  /* S-Function Block: <Root>/Packet Input */
  {
    uint8_T indata[4U];
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 4U,
      &matlab_crutches_P.PacketInput_PacketID, (double*) indata, NULL);
    matlab_crutches_B.PacketInput_o2 = status & 0x1;/* Data Ready port */
    if (status & 0x1) {
      RTWin_ANYTYPEPTR indp;
      indp.p_uint8_T = indata;
      matlab_crutches_B.PacketInput_o1 = *indp.p_int32_T++;
    }
  }
}

/* Model update function */
void matlab_crutches_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++matlab_crutches_M->Timing.clockTick0)) {
    ++matlab_crutches_M->Timing.clockTickH0;
  }

  matlab_crutches_M->Timing.t[0] = matlab_crutches_M->Timing.clockTick0 *
    matlab_crutches_M->Timing.stepSize0 + matlab_crutches_M->Timing.clockTickH0 *
    matlab_crutches_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void matlab_crutches_initialize(void)
{
}

/* Model terminate function */
void matlab_crutches_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  matlab_crutches_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  matlab_crutches_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  matlab_crutches_initialize();
}

void MdlTerminate(void)
{
  matlab_crutches_terminate();
}

/* Registration function */
RT_MODEL_matlab_crutches_T *matlab_crutches(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)matlab_crutches_M, 0,
                sizeof(RT_MODEL_matlab_crutches_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = matlab_crutches_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    matlab_crutches_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    matlab_crutches_M->Timing.sampleTimes =
      (&matlab_crutches_M->Timing.sampleTimesArray[0]);
    matlab_crutches_M->Timing.offsetTimes =
      (&matlab_crutches_M->Timing.offsetTimesArray[0]);

    /* task periods */
    matlab_crutches_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    matlab_crutches_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(matlab_crutches_M, &matlab_crutches_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = matlab_crutches_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    matlab_crutches_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(matlab_crutches_M, 10.0);
  matlab_crutches_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  matlab_crutches_M->Sizes.checksums[0] = (2488328558U);
  matlab_crutches_M->Sizes.checksums[1] = (2852722679U);
  matlab_crutches_M->Sizes.checksums[2] = (1547123801U);
  matlab_crutches_M->Sizes.checksums[3] = (923110789U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    matlab_crutches_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(matlab_crutches_M->extModeInfo,
      &matlab_crutches_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(matlab_crutches_M->extModeInfo,
                        matlab_crutches_M->Sizes.checksums);
    rteiSetTPtr(matlab_crutches_M->extModeInfo, rtmGetTPtr(matlab_crutches_M));
  }

  matlab_crutches_M->solverInfoPtr = (&matlab_crutches_M->solverInfo);
  matlab_crutches_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&matlab_crutches_M->solverInfo, 0.001);
  rtsiSetSolverMode(&matlab_crutches_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  matlab_crutches_M->blockIO = ((void *) &matlab_crutches_B);
  (void) memset(((void *) &matlab_crutches_B), 0,
                sizeof(B_matlab_crutches_T));

  /* parameters */
  matlab_crutches_M->defaultParam = ((real_T *)&matlab_crutches_P);

  /* states (dwork) */
  matlab_crutches_M->dwork = ((void *) &matlab_crutches_DW);
  (void) memset((void *)&matlab_crutches_DW, 0,
                sizeof(DW_matlab_crutches_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    matlab_crutches_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  matlab_crutches_M->Sizes.numContStates = (0);/* Number of continuous states */
  matlab_crutches_M->Sizes.numY = (0); /* Number of model outputs */
  matlab_crutches_M->Sizes.numU = (0); /* Number of model inputs */
  matlab_crutches_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  matlab_crutches_M->Sizes.numSampTimes = (1);/* Number of sample times */
  matlab_crutches_M->Sizes.numBlocks = (3);/* Number of blocks */
  matlab_crutches_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  matlab_crutches_M->Sizes.numBlockPrms = (3);/* Sum of parameter "widths" */
  return matlab_crutches_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
