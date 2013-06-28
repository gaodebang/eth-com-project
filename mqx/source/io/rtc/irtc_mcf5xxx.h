/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: irtc_mcf5xxx.h$
* $Version : 3.8.12.0$
* $Date    : Sep-17-2012$
*
* Comments:
*
*   Processor family specific file needed for RTC module.
*
*END************************************************************************/

#ifndef __irtc_mcf5xxx_h__
#define __irtc_mcf5xxx_h__

/******************************************************************************
 * interrupt masks definitions (RTC_ISR and RTC_IER registers)                *
 ******************************************************************************/  
#ifndef RTC_INVALID_TIME
#define  RTC_INVALID_TIME  (RTC_ERROR_BASE | 0x01)
#endif 

/* IRTC time reperesentation */
typedef struct rtc_time_struct
{
    uint_8  seconds;
    uint_8  minutes;
    uint_8  hours;
    uint_8  days;
    uint_8  wday;
    uint_8  month;
    uint_16 year;
} RTC_TIME_STRUCT, _PTR_ RTC_TIME_STRUCT_PTR;

/*----------------------------------------------------------------------*/
/*
**                    FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

void     _rtc_lock (void);
_mqx_uint     _rtc_unlock (void);
_mqx_uint     _rtc_tested_unlock ( _mqx_uint );
void     _rtc_set_time (RTC_TIME_STRUCT_PTR time);
void     _rtc_get_time (RTC_TIME_STRUCT_PTR time);
void     _rtc_set_alarm (RTC_TIME_STRUCT_PTR time);
void     _rtc_get_alarm (RTC_TIME_STRUCT_PTR time);
void     _rtc_set_stopwatch (uint_32 minutes);
uint_32  _rtc_get_stopwatch (void);
void     _rtc_inc_upcounter(void);
uint_32  _rtc_get_upcounter(void);
_mqx_uint _rtc_write_to_standby_ram(uint_32 dst_address, uint_8 * src_ptr, uint_32  size);
_mqx_uint _rtc_read_from_standby_ram(uint_32  src_address, uint_8 * dst_ptr, uint_32  size);
void _rtc_time_to_mqx_time(RTC_TIME_STRUCT_PTR rtc_time, TIME_STRUCT_PTR mqx_time);
void _rtc_time_from_mqx_time(TIME_STRUCT_PTR mqx_time, RTC_TIME_STRUCT_PTR rtc_time);
void _rtc_time_to_mqx_date(RTC_TIME_STRUCT_PTR rtc_time, DATE_STRUCT_PTR mqx_date);
void _rtc_time_from_mqx_date(DATE_STRUCT_PTR mqx_date, RTC_TIME_STRUCT_PTR rtc_time);
_mqx_int _rtc_sync_with_mqx(boolean update_mqx);
_mqx_int _rtc_set_time_mqxd(DATE_STRUCT_PTR time);
void _rtc_get_time_mqxd(DATE_STRUCT_PTR time);
_mqx_int _rtc_set_alarm_mqxd(DATE_STRUCT_PTR time);
void _rtc_get_alarm_mqxd(DATE_STRUCT_PTR time);

#ifdef __cplusplus
}
#endif

#endif   /* __irtc_mcf5xxx_h__ */
