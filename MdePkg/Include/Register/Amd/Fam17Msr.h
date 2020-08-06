/** @file
  MSR Definitions.

  Provides defines for Machine Specific Registers(MSR) indexes. Data structures
  are provided for MSRs that contain one or more bit fields.  If the MSR value
  returned is a single 32-bit or 64-bit value, then a data structure is not
  provided for that MSR.

  Copyright (c) 2017, Advanced Micro Devices. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

  @par Specification Reference:
  AMD64 Architecture Programming Manual volume 2, March 2017, Sections 15.34

**/

#ifndef __FAM17_MSR_H__
#define __FAM17_MSR_H__

/**
  Secure Encrypted Virtualization - Encrypted State (SEV-ES) GHCB register

**/
#define MSR_SEV_ES_GHCB                    0xc0010130

/**
  MSR information returned for #MSR_SEV_ES_GHCB
**/
typedef union {
  struct {
    UINT32  Function:12;
    UINT32  Reserved1:20;
    UINT32  Reserved2:32;
  } GhcbInfo;

  struct {
    UINT8   Reserved[3];
    UINT8   SevEncryptionBitPos;
    UINT16  SevEsProtocolMin;
    UINT16  SevEsProtocolMax;
  } GhcbProtocol;

  struct {
    UINT32  Function:12;
    UINT32  ReasonCodeSet:4;
    UINT32  ReasonCode:8;
    UINT32  Reserved1:8;
    UINT32  Reserved2:32;
  } GhcbTerminate;

  struct {
    UINT64  Function :12;
    UINT64  GuestFrameNumber :40;
    UINT64  Rsvd :11;
    UINT64  RmpPageSize :1;
  } GhcbSnpMemOp;

  VOID    *Ghcb;

  UINT64  GhcbPhysicalAddress;
} MSR_SEV_ES_GHCB_REGISTER;

#define GHCB_INFO_SEV_INFO                 1
#define GHCB_INFO_SEV_INFO_GET             2
#define GHCB_INFO_CPUID_REQUEST            4
#define GHCB_INFO_CPUID_RESPONSE           5
#define GHCB_INFO_SNP_MEM_OP_PRIVATE       6
#define GHCB_INFO_SNP_MEM_OP_SHARED        7
#define GHCB_INFO_TERMINATE_REQUEST        256

#define GHCB_TERMINATE_GHCB                0
#define GHCB_TERMINATE_GHCB_GENERAL        0
#define GHCB_TERMINATE_GHCB_PROTOCOL       1

/**
  Secure Encrypted Virtualization (SEV) status register

**/
#define MSR_SEV_STATUS                     0xc0010131

/**
  MSR information returned for #MSR_SEV_STATUS
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    ///
    /// [Bit 0] Secure Encrypted Virtualization (Sev) is enabled
    ///
    UINT32  SevBit:1;

    ///
    /// [Bit 1] Secure Encrypted Virtualization Encrypted State (SevEs) is enabled
    ///
    UINT32  SevEsBit:1;

    ///
    /// [Bit 2] Secure Nested Paging (SevSnp) is enabled
    ///
    UINT32  SevSnpBit:1;

    UINT32  Reserved:29;
  } Bits;
  ///
  /// All bit fields as a 32-bit value
  ///
  UINT32  Uint32;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_SEV_STATUS_REGISTER;

#endif
