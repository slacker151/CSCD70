// RUN: clang -O2 -emit-llvm -c %s -o %basename_t.bc
// RUN: llvm-dis %basename_t.bc -o=%basename_t.ll
// RUN: opt -load %dylibdir/libPassManager%dylibext \
// RUN:     -transform -another-transform -disable-output 2>&1 %basename_t.bc | \
// RUN: FileCheck --match-full-lines %s

// CHECK: Analysis
// CHECK-NEXT: Transform
// CHECK-NEXT: 1, 2, 3, 
// CHECK-NEXT: Another Transform
// CHECK-NEXT: 1, 2, 3, 
int main() {
  return 0;
}
