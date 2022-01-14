//RDA FM 5807P drv
//Version 2.6


/***************************************************
RDA5807P interfaces
****************************************************/
void RDA5807P_PowerOnReset(void);
void RDA5807P_PowerOffProc(void);

void RDA5807P_SetMute(uint8 mute);
uint16 RDA5807P_FreqToChan(uint16 frequency);
void RDA5807P_SetFreq( int16 curf );
uint8 RDA5807P_ValidStop(int16 freq);
uint8 RDA5807P_GetSigLvl( int16 curf );
void RDA5807P_SetVolumeLevel(uint8 level);
bool RDA5807P_Intialization(void);
uint16 RDA5807P_ChanToFreq(uint16 chan);
