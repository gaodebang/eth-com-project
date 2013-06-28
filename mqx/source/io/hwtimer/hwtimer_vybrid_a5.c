/*HEADER********************************************************************
 *
 * Copyright (c) 2013 Freescale Semiconductor;
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
 * $FileName: hwtimer_vybrid_a5.c$
 * $Version : 4.0.1$
 * $Date : Jan-18-2013$
 *
 * Comments:
 *
 *   This file contains vybrid cortext A5 specific functions of the hwtimer
 *   component.
 *
 *END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include "hwtimer.h"

/*!
 * \cond DOXYGEN_PRIVATE
 * Macro return number of item in pit_vectors_table array
 */
#define PIT_INTERRUPT_COUNT 1

/*!
 * \cond DOXYGEN_PRIVATE
 * Macro return size of pit_hwtimers_array.
 */
#define PIT_HWTIMERS_ARRAY_SIZE 8  
  
/* Array of PIT interrupt vectors*/
/*!
 * \cond DOXYGEN_PRIVATE
 * \brief Array of PIT interrupt vectors
 */
const _mqx_uint pit_vectors_table[] =
    {
        INT_PIT
    };
   
/*!
 * \cond DOXYGEN_PRIVATE
 * \brief Array where hwtimers should be stored. 
 *
 * Size of array is count of all channels for all pit devices
 */
HWTIMER_PTR pit_hwtimers_array[PIT_HWTIMERS_ARRAY_SIZE] = {0};

/*!
 * \cond DOXYGEN_PRIVATE
 *
 * \brief This function performs BSP-specific initialization related to pit
 *
 * \param dev_num[in]   Number of PIT module.
 *
 * \return MQX_OK Success.
 *
 * \see pit_get_vectors
 * \see pit_get_hwtimers_array
 */
_mqx_int pit_io_init
(
    uint_32 dev_num
)
{
    return MQX_OK;
}

/*!
 * \cond DOXYGEN_PRIVATE
 *
 * \brief This function get array of vectors and count of items in this array.
 *
 * \param pit_vectors_table_ptr[out]  Used to get pit_vectors_table.
 *
 * \return PIT_INTERRUPT_COUNT Count of interrupt vectors for PIT module.
 *
 * \see pit_io_init
 * \see pit_get_hwtimers_array
 */
uint_32 pit_get_vectors
(
    uint_32 pit_number,
    const _mqx_uint **pit_vectors_table_ptr
)
{
    switch (pit_number)
    {
        case 0:
            *pit_vectors_table_ptr = pit_vectors_table;
            break;
        default:
            *pit_vectors_table_ptr = NULL;
    }

    return PIT_INTERRUPT_COUNT;
}

/*!
 * \cond DOXYGEN_PRIVATE
 *
 * \brief This function get array of hwtimer and count of items in this array.
 *
 * \param pit_vectors_table_ptr[out]  Used to get pit_hwtimers_array.
 *
 * \return PIT_HWTIMERS_ARRAY_SIZE Size of pit_hwtimers_array
 *
 * \see pit_io_init
 * \see pit_get_vectors
 */
uint_32 pit_get_hwtimers_array
(
    HWTIMER_PTR ** hwtimers_array
)
{
    *hwtimers_array = pit_hwtimers_array;
    return PIT_HWTIMERS_ARRAY_SIZE;
}
