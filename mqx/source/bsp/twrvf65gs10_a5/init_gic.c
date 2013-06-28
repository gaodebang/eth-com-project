/**HEADER********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
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
* $FileName: cortexa5.h$
* $Version : 3.8.7.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*END************************************************************************/

#include "mqx_inc.h"
#include "bsp.h"
#include "bsp_prv.h"
#include "io_rev.h"
#include "bsp_rev.h"


/* This function sits in a tight loop (interrupts will be disabled) for
 * exceptions that we are not currently handling. */
void unhandled_exception(void) {
    while (1);
}

/* Initialize the interrupt controller and turn ISRs on. */
void init_gic(void) {
    int i;
    uint_16 *ptr;
    extern void _gic_init(void);

    _gic_init();

    // set non-secure all interrupts
    GICD_IGROUPR(0) = 0xffffffff;
    GICD_IGROUPR(1) = 0xffffffff;
    GICD_IGROUPR(2) = 0xffffffff;
    GICD_IGROUPR(3) = 0xffffffff;
    GICD_IGROUPR(4) = 0xffffffff;

    // clear pending flags all interrupts
    GICD_ICPENDR(0) = 0xffffffff;
    GICD_ICPENDR(1) = 0xffffffff;
    GICD_ICPENDR(2) = 0xffffffff;
    GICD_ICPENDR(3) = 0xffffffff;
    GICD_ICPENDR(4) = 0xffffffff;

    // CPU interface
    //GICC_PMR = 0xff;    // set priority
    GICC_CTLR = 7;      // enable signaling of interrupts

    // distributor
    GICD_CTLR = 3;      // interrupts forwarded

    // route all interrupts to core 1
    for (i = 0, ptr = (uint_16*)MSCM_IRSPRC0; i < 112; i++, ptr++) {
        *ptr = MSCM_IRSPRCn_CP1_MASK;
    }
}
