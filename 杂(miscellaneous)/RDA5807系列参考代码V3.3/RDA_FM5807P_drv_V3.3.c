//RDA FM 5807P drv
//Version 2.1


typedef unsigned char           uint8;
typedef unsigned short int      uint16;
typedef short int               int16;


#define READ	        1   
#define WRITE	        0   
                            
#define ADRW 	        0x20
#define ADRR 	        0x21


//#define                 _SHARE_CRYSTAL_24MHz_   //共用24MHz晶振，请打开此宏
//#define                 _SHARE_CRYSTAL_12MHz_   //共用12MHz晶振，请打开此宏
//#define                 _SHARE_CRYSTAL_32KHz_   //共用32KHz晶振，请打开此宏
//#define                 _FM_STEP_50K_           //50K步进，请打开此宏


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
uint16 gChipID = 0;
uint8 RDA5807P_REGW[10];

/***************************************************
RDA5807P
****************************************************/
uint8 RDA5807P_initialization_reg[]={
#if defined(_SHARE_CRYSTAL_24MHz_)
    0xC0, 0x51, //02H:
#elif defined(_SHARE_CRYSTAL_12MHz_)
    0xC0, 0x11, //02H:
#elif defined(_SHARE_CRYSTAL_32KHz_)
    0xC0, 0x01, //02H:
#else
    0xC0, 0x01,
#endif

#if defined(_FM_STEP_50K_)
    0x00, 0x12,        
#else
    0x00, 0x10,
#endif
    0x04, 0x00,        
    0x88, 0xAF, //05H: 
    0x00, 0x00,        
    0x5E, 0xC6,        
    0x50, 0x96,        
    0x00, 0x00,        
    0x40, 0x00, //0AH: 
    0x00, 0x8F,        
    0x00, 0x00,        
    0x00, 0x00,        
    0x00, 0x00,        
    0x00, 0x00,        
    0xF0, 0x05, //10H: 
    0x90, 0x00,        
    0xF4, 0x84,        
    0x70, 0x01,        
    0x40, 0xF0,        
    0x21, 0x80, //15H: 
    0x7A, 0xD0,        
    0x3E, 0x40,        
    0x55, 0xA9,        
    0xE8, 0x48,        
    0x50, 0x80, //1AH: 
    0x00, 0x00,        
    0x37, 0xB6,        
    0x40, 0x0C,        
    0x07, 0x9B,        
    0x4C, 0x1D,        
    0x81, 0x11, //20H: 
    0x45, 0xC0,        
};



uint8 RDA5807PE_initialization_reg[]={
#if defined(_SHARE_CRYSTAL_24MHz_)
    0xc4, 0x51, //02H:
#elif defined(_SHARE_CRYSTAL_12MHz_)
    0xc4, 0x11, //02H:
#elif defined(_SHARE_CRYSTAL_32KHz_)
    0xc4, 0x01, //02H:
#else
    0xC0, 0x01,
#endif

#if defined(_FM_STEP_50K_)
    0x1b, 0x92,
    0x0C, 0x00,
#else       //Step 100K
    0x00, 0x10,
    0x04, 0x00,
#endif

    0x86, 0xad, //05H:
    0x80, 0x00,
    0x5F, 0x1A, //07H
    0x5e, 0xc6,
    0x00, 0x00,
    0x40, 0x6e, //0AH: 
    0x2d, 0x80,
    0x58, 0x03,
    0x58, 0x04,
    0x58, 0x04,
    0x58, 0x04,
    0x00, 0x47, //10H: 
    0x90, 0x00,
    0xF5, 0x87,
    0x7F, 0x0B, //13H:
	0x04, 0xF1,
	0x5E, 0xc0, //15H: 0x42, 0xc0
    0x41, 0xe0,
    0x50, 0x6f,
    0x55, 0x92,
    0x00, 0x7d,
    0x10, 0xC0,//1AH
    0x07, 0x80,
    0x41, 0x1d,//1CH,
    0x40, 0x06,
    0x1f, 0x9B,
    0x4c, 0x2b,//1FH. 
    0x81, 0x10, //20H: 
    0x45, 0xa0,// 21H

#if defined(_FM_STEP_50K_)
    0x55, 0x3F, //22H
#else
    0x19, 0x3F, //22H
#endif

    0xaf, 0x40, 
	0x06, 0x81,
    0x1b, 0x2a, //25H
    0x0D, 0x04,
	0x80, 0x9F, //0x80, 0x2F, 
    0x17, 0x8A,
    0xD3, 0x49,
    0x11, 0x42,
    0xA0, 0xC4, //2BH
	0x3E, 0xBB,
    0x00, 0x00,
    0x58, 0x04,
    0x58, 0x04, //2FH
    0x58, 0x04,
    0x00, 0x74,
    0x3D, 0x00,
    0x03, 0x0C,
    0x2F, 0x68,
    0x38, 0x77, //35H
};


uint8 RDA5807PH_initialization_reg[]={
#if defined(_SHARE_CRYSTAL_24MHz_)
    0xC4, 0x51, //02H:
#elif defined(_SHARE_CRYSTAL_12MHz_)
    0xC4, 0x11, //02H:
#elif defined(_SHARE_CRYSTAL_32KHz_)
    0xC4, 0x01, //02H:
#else
    0xC0, 0x01,
#endif
#if defined(_FM_STEP_50K_)
    0x00,0x12,
#else
    0x00,0x10,
#endif
    0x04,0x00,
    0x86,0xBF,  //05H   
    0x40,0x00,
    0x56,0xC6,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,  //0AH
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x00,
    0x00,0x06,  //10H
    0x00,0x19, //
    0x2A,0x11,
    0x00,0x2E,
    0x2A,0x30,
    0xB8,0x3C,  //15H
    0x90,0x00,
    0x2A,0x91,
    0x84,0x12,
    0x00,0xA8,
    0xC4,0x00,  //1AH
    0xE0,0x00,
    0x30,0x1D,//0x24,0x9D,1cH
    0x81,0x6A,
    0x46,0x08,
    0x00,0x86,  //1FH
    0x06,0x61,  //20H
    0x00,0x00,
    0x10,0x9E,
    0x24,0xC9,//   0x24,0x47,//0830//23H
    0x04,0x08,//0830
    0x06,0x08,  //0x06,0x08,//0830  //0X25H
    0xE1,0x05,
    0x3B,0x6C,
    0x2B,0xEC,
    0x09,0x0F,
    0x34,0x14,  //2AH
    0x14,0x50,
    0x09,0x6D,
    0x2D,0x96,
    0x01,0xDA,
    0x2A,0x7B,
    0x08,0x21,   //30H
    0x13,0xD5,
    0x48,0x91,
    0x00,0xbc,
    0x08,0x96,   //34H
    0x15,0x3C,  //35H
    0x0B,0x80,   //36H
    0x25,0xC7,   //37H
    0x00,0x00,   //38H
	0x3C,0x58,
	0x2A,0x50,
	0x26,0x2C,
	0x06,0x08,
	0x02,0x00,
	0x00,0x00,
};



uint8 RDA5807N_initialization_reg[]={
#if defined(_SHARE_CRYSTAL_24MHz_)
    0xC4, 0x51, //02H:
#elif defined(_SHARE_CRYSTAL_12MHz_)
    0xC4, 0x11, //02H:
#elif defined(_SHARE_CRYSTAL_32KHz_)
    0xC4, 0x01, //02H:
#else
    0xC0, 0x01,
#endif
    0x00, 0x00,
    0x04, 0x00,
    0xC6, 0xad, //05h
    0x60, 0x00,
    0x42, 0xC6,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,  //0x0ah
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,  //0x10h
    0x00, 0x19,
    0x2a, 0x11,
    0xB0, 0x42,  
    0x2A, 0x11,  
    0xb8, 0x31,  //0x15h 
    0xc0, 0x00,
    0x2a, 0x91,
    0x94, 0x00,
    0x00, 0xa8,
    0xc4, 0x00,  //0x1ah
    0xF7, 0xcF,   
    0x2A, 0xDC,  //0x1ch
    0x80, 0x6F, 
    0x46, 0x08,
    0x00, 0x86,
    0x06, 0x61, //0x20H
    0x00, 0x00,
    0x10, 0x9E,
    0x23, 0xC8,
    0x04, 0x06,
    0x0E, 0x1C, //0x25H
}


/**
 * @brief Reset RDA5807P while power on RDA5807P
 * @author RDA RDA Ri'an Zeng
 * @date 2008-11-05
 * @param void
 * @return void
 * @retval
 */
void  RDA5807P_PowerOnReset(void)
{
    RDA5807P_Intialization(); 
}




/**
 * @brief RDA5807P power off function
 * @author RDA Ri'an Zeng
 * @date 2008-11-05
 * @param void
 * @return void
 * @retval
 */
void  RDA5807P_PowerOffProc(void)
{
	RDA5807P_REGW[1] &= (~1);
	OperationRDAFM_2w(WRITE, &(RDA5807P_REGW[0]), 2);

}






/**
 * @brief Set RDA5807P into mute mode
 * @author RDA Ri'an Zeng
 * @date 2008-11-05
 * @param bool mute: if mute is true,then set mute; if mute is false,then set no mute
 * @return void
 * @retval
 */
void RDA5807P_SetMute(bool mute)
{
	if(mute)
	 	RDA5807P_REGW[0] &=  ~(1<<6);
	else
		RDA5807P_REGW[0] |=	1<<6;

	OperationRDAFM_2w(WRITE, &(RDA5807P_REGW[0]), 2);
    delayms(50);    //Dealy 50 ms
}




/**
 * @brief Cover the frequency to channel value
 * @author RDA Ri'an Zeng
 * @date 2008-11-05
 * @param uint16 frequency:covered frequency
 * @return uint16: channel value
 * @retval
 */
uint16 RDA5807P_FreqToChan(uint16 frequency) 
{
	uint8 channelSpacing;
	uint16 bottomOfBand;
	uint16 channel;

	if ((RDA5807P_REGW[3] & 0x0c) == 0x00) 
		bottomOfBand = 8700;
	else if ((RDA5807P_REGW[3] & 0x0c) == 0x04)	
		bottomOfBand = 7600;
	else if ((RDA5807P_REGW[3] & 0x0c) == 0x08)	
		bottomOfBand = 7600;	
	if ((RDA5807P_REGW[3] & 0x03) == 0x00) 
		channelSpacing = 10;
	else if ((RDA5807P_REGW[3] & 0x03) == 0x01) 
		channelSpacing = 10;
	else if ((RDA5807P_REGW[3] & 0x03) == 0x02) 
		channelSpacing = 5;
	channel = (frequency - bottomOfBand) / channelSpacing;
	return (channel);
}




uint16 RDA5807P_ChanToFreq(uint16 chan) 
{
	uint8 channelSpacing;
	uint16 bottomOfBand;
	uint16 freq;

	if ((RDA5807P_REGW[3] & 0x0c) == 0x00) 
		bottomOfBand = 8700;
	else if ((RDA5807P_REGW[3] & 0x0c) == 0x04)	
		bottomOfBand = 7600;
	else if ((RDA5807P_REGW[3] & 0x0c) == 0x08)	
		bottomOfBand = 7600;	
	if ((RDA5807P_REGW[3] & 0x03) == 0x00) 
		channelSpacing = 10;
	else if ((RDA5807P_REGW[3] & 0x03) == 0x01) 
		channelSpacing = 10;
	else if ((RDA5807P_REGW[3] & 0x03) == 0x02) 
		channelSpacing = 5;
	freq = bottomOfBand + chan * channelSpacing;

	return (freq);
}




/**
 * @brief Set frequency function
 * @author RDA Ri'an Zeng
 * @date 2008-11-05
 * @param int16 curFreq:frequency value
 * @return void
 * @retval
 */
void RDA5807P_SetFreq( int16 curFreq )
{   
	uint16 curChan;
	
	curChan=RDA5807P_FreqToChan(curFreq);
	
	//SetNoMute
	RDA5807P_REGW[0] |=	1<<7;
	RDA5807P_REGW[2]=curChan>>2;
	RDA5807P_REGW[3]=(((curChan&0x0003)<<6)|0x10) | (RDA5807P_REGW[3]&0x0f);	//set tune bit
	
	OperationRDAFM_2w(WRITE, &(RDA5807P_REGW[0]), 4);
	delayms(50);     //Delay five ms
}





/**
 * @brief Station judge for auto search
 * @In auto search mode,uses this function to judge the frequency if has a station
 * @author RDA Ri'an Zeng
 * @date 2008-11-05
 * @param int16 freq:frequency value
 * @return bool: if return true,the frequency has a true station;otherwise doesn't have a station
 * @retval
 */
bool RDA5807P_ValidStop(int16 freq)
{
	uint8 RDA5807P_reg_data[4]={0};	
	uint8 falseStation = 0;
	uint8 i=0;
	uint16 curChan;
	
	curChan=RDA5807P_FreqToChan(freq);
	
	//SetNoMute
	RDA5807P_REGW[0] |=	1<<7;
	
	RDA5807P_reg_data[0]=RDA5807P_REGW[0];
	RDA5807P_reg_data[1]=RDA5807P_REGW[1];
	RDA5807P_reg_data[2]=curChan>>2;
	RDA5807P_reg_data[3]=(((curChan&0x0003)<<6)|0x10) | (RDA5807P_REGW[3]&0x0f);
	OperationRDAFM_2w(WRITE,&(RDA5807P_reg_data[0]), 4);
	
	delayms(50);    //Dealy 25 ms

    if (0x5808 == gChipID)
        OperationRDAFM_2w(READ,&(RDA5807P_reg_data[0]), 4);	
    else
    {
    	do
    	{
    		i++;
    		if(i>5) return 0; 
    
    		delayms(30);
    		//read REG0A&0B	
    		OperationRDAFM_2w(READ,&(RDA5807P_reg_data[0]), 4);	
    	}while((RDA5807P_reg_data[0]&0x40)==0);
     }

	//check FM_TURE
	if((RDA5807P_reg_data[2] &0x01)==0) falseStation=1;
	
	if(freq==9600) falseStation=1;
		
	if (falseStation==1)
		return 0;   
	else 
		return 1;
}





/**
 * @brief Get the signal level(RSSI) of the current frequency
 * @author RDA Ri'an Zeng
 * @date 2008-11-05
 * @param int16 curf:frequency value
 * @return uint8: the signal level(RSSI)
 * @retval
 */
uint8 RDA5807P_GetSigLvl( int16 curf )
{    
    uint8 RDA5807P_reg_data[4]={0};	

    OperationRDAFM_2w(READ,&(RDA5807P_reg_data[0]), 4);
	delayms(50);    //Dealy 50 ms
    return  (RDA5807P_reg_data[2]>>1);  /*返回rssi*/
}





/**
 * @brief Set FM volume
 * @It has better use the system volume operation to replace this function
 * @author RDA Ri'an Zeng
 * @date 2008-11-05
 * @param uint8 level: volume value
 * @return void
 * @retval
 */
void RDA5807P_SetVolumeLevel(uint8 level)
{
    uint8 RDA5807P_reg_data[8];
    uint8 i = 0;

    for (i=0;i<8;i++)
        RDA5807P_reg_data[i] = RDA5807P_REGW[i];

    RDA5807P_reg_data[7]=(( RDA5807P_REG[7] & 0xf0 ) | (level & 0x0f)); 
    
    RDA5807P_reg_data[3] &= (~(0x10));

	OperationRDAFM_2w(WRITE, &(RDA5807P_reg_data[0]), 8);
    delayms(50);    //Dealy 50 ms
}





/**
 * @brief Initialize RDA5807P
 * @author RDA Ri'an Zeng
 * @date 2008-11-05
 * @param void
 * @return bool:if true,the operation is successful;otherwise is failed
 * @retval
 */
bool  RDA5807P_Intialization(void)
{
	uint8 error_ind = 0;
	uint8 RDA5807P_REGR[10]={0x0};
    uint8 i = 0;

    RDA5807P_REGW[0] = 0x00;
    RDA5807P_REGW[1] = 0x02;

	error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807P_REGW[0], 2);
	delayms(50);

	error_ind = OperationRDAFM_2w(READ, (uint8 *)&RDA5807P_REGR[0], 10);
	delayms(50);

    gChipID = RDA5807P_REGR[8];
    gChipID = ((gChipID<<8) | RDA5807P_REGR[9]);

    if (gChipID == 0x5808)  //RDA5807N
    {
        for (i=0;i<8;i++)
            RDA5807P_REGW[i] = RDA5807N_initialization_reg[i];
     
        error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807N_initialization_reg[0], 2);
        delayms(600); 
	    error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807N_initialization_reg[0], sizeof(RDA5807N_initialization_reg));
    }
    else if (gChipID == 0x5804)     //RDA5807PE,RDA5807SP
    {
        for (i=0;i<8;i++)
            RDA5807P_REGW[i] = RDA5807PE_initialization_reg[i];
     
        error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807PE_initialization_reg[0], 2);
        delayms(600); 
	    error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807PE_initialization_reg[0], sizeof(RDA5807PE_initialization_reg));
    }
    else if (gChipID == 0x5801)     //RDA5807H,RDA5807HP
    {
        for (i=0;i<8;i++)
            RDA5807P_REGW[i] = RDA5807PH_initialization_reg[i];
     
        error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807PH_initialization_reg[0], 2);
        delayms(600); 
	    error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807PH_initialization_reg[0], sizeof(RDA5807PH_initialization_reg));
        delayms(100);

		do
		{
			i++;
			if(i>10) 
				return 0; 
			
		RDA5807P_SetFreq(8750);

		delayms(10);   	

		//read REG0A&0B	
		OperationRDAFM_2w(READ,&(RDA5807P_REGR[0]), 4);
		if((RDA5807P_REGR[3]&0x80)==0)
			{
				RDA5807_REGW[1] &= 0xFE;	
				error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807_REGW[0], 2);
				delayms(50);	
				RDA5807_REGW[1] |= 0x01;
				error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807_REGW[0], 2);
				delayms(50);

		}
		}while((RDA5807P_REGR[3]&0x80)==0);
    }
    else
    {
        gChipID = RDA5807P_REGR[4];
        gChipID = ((gChipID<<8) | RDA5807P_REGR[5]);
    }
    
    if ((gChipID == 0x5802) || (gChipID == 0x5803))
    {
        gChipID = 0x5802;

        for (i=0;i<8;i++)
            RDA5807P_REGW[i] = RDA5807P_initialization_reg[i];


        error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807P_initialization_reg[0], 2);
        delayms(600); 
        error_ind = OperationRDAFM_2w(WRITE, (uint8 *)&RDA5807P_initialization_reg[0], sizeof(RDA5807P_initialization_reg));

    }

	delayms(50);         //Dealy 50 ms
	
	
	if (error_ind )
	   return 0;
	else
	   return 1;
}

