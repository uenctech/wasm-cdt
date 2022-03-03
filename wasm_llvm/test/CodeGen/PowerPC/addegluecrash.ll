; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc -O0 < %s | FileCheck %s
target datalayout = "e-m:e-i64:64-n32:64"
target triple = "powerpc64le-unknown-linux-gnu"

define void @bn_mul_comba8(i64* nocapture %r, i64* nocapture readonly %a, i64* nocapture readonly %b) {
; CHECK-LABEL: bn_mul_comba8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    ld 6, 0(4)
; CHECK-NEXT:    ld 7, 0(5)
; CHECK-NEXT:    mulhdu 8, 7, 6
; CHECK-NEXT:    ld 4, 8(4)
; CHECK-NEXT:    mulld 9, 4, 6
; CHECK-NEXT:    mulhdu 4, 4, 6
; CHECK-NEXT:    addc 6, 9, 8
; CHECK-NEXT:    addze 4, 4
; CHECK-NEXT:    ld 5, 8(5)
; CHECK-NEXT:    mulld 8, 5, 7
; CHECK-NEXT:    mulhdu 5, 5, 7
; CHECK-NEXT:    addc 6, 6, 8
; CHECK-NEXT:    addze 5, 5
; CHECK-NEXT:    add 4, 5, 4
; CHECK-NEXT:    cmpld 7, 4, 5
; CHECK-NEXT:    mfocrf 10, 1
; CHECK-NEXT:    rlwinm 10, 10, 29, 31, 31
; CHECK-NEXT:    # implicit-def: $x4
; CHECK-NEXT:    mr 4, 10
; CHECK-NEXT:    clrldi 4, 4, 32
; CHECK-NEXT:    std 4, 0(3)
; CHECK-NEXT:    blr
  %1 = load i64, i64* %a, align 8
  %conv = zext i64 %1 to i128
  %2 = load i64, i64* %b, align 8
  %conv2 = zext i64 %2 to i128
  %mul = mul nuw i128 %conv2, %conv
  %shr = lshr i128 %mul, 64
  %agep = getelementptr inbounds i64, i64* %a, i64 1
  %3 = load i64, i64* %agep, align 8
  %conv14 = zext i64 %3 to i128
  %mul15 = mul nuw i128 %conv14, %conv
  %add17 = add i128 %mul15, %shr
  %shr19 = lshr i128 %add17, 64
  %conv20 = trunc i128 %shr19 to i64
  %bgep = getelementptr inbounds i64, i64* %b, i64 1
  %4 = load i64, i64* %bgep, align 8
  %conv28 = zext i64 %4 to i128
  %mul31 = mul nuw i128 %conv28, %conv2
  %conv32 = and i128 %add17, 18446744073709551615
  %add33 = add i128 %conv32, %mul31
  %shr35 = lshr i128 %add33, 64
  %conv36 = trunc i128 %shr35 to i64
  %add37 = add i64 %conv36, %conv20
  %cmp38 = icmp ult i64 %add37, %conv36
  %conv148 = zext i1 %cmp38 to i64
  store i64 %conv148, i64* %r, align 8
  ret void
}

