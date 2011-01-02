/* sd2iec - SD/MMC to Commodore serial bus interface/controller
   Copyright (C) 2007-2011  Ingo Korb <ingo@akana.de>

   Inspiration and low-level SD/MMC access based on code from MMC2IEC
     by Lars Pontoppidan et al., see sdcard.c|h and config.h.

   FAT filesystem access based on code from ChaN and Jim Brain, see ff.c|h.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License only.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


   iec-bus.h: A few wrappers around the port definitions

*/

#ifndef IEC_BUS_H
#define IEC_BUS_H

#define set_atn(state)   do { if (state) IEC_OUTPUT &= ~IEC_OBIT_ATN;   else IEC_OUTPUT |= IEC_OBIT_ATN;   } while(0)
#define set_data(state)  do { if (state) IEC_OUTPUT &= ~IEC_OBIT_DATA;  else IEC_OUTPUT |= IEC_OBIT_DATA;  } while(0)
#define set_clock(state) do { if (state) IEC_OUTPUT &= ~IEC_OBIT_CLOCK; else IEC_OUTPUT |= IEC_OBIT_CLOCK; } while(0)
#define set_srq(state)   do { if (state) IEC_OUTPUT &= ~IEC_OBIT_SRQ;   else IEC_OUTPUT |= IEC_OBIT_SRQ;   } while(0)
#define toggle_srq()     IEC_INPUT |= IEC_OBIT_SRQ


#define IEC_ATN   (IEC_INPUT & IEC_BIT_ATN)
#define IEC_DATA  (IEC_INPUT & IEC_BIT_DATA)
#define IEC_CLOCK (IEC_INPUT & IEC_BIT_CLOCK)
#define IEC_SRQ   (IEC_INPUT & IEC_BIT_SRQ)

#endif