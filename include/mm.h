#ifndef _MM_H
#define _MM_H

#define PAGE_SHIFT      12
#define TABLE_SHIFT     9
#define SECTION_SHIFT   (PAGE_SHIFT + TABLE_SHIFT)

#define PAGE_SIZE       (1 << PAGE_SHIFT)
#define SECTION_SIZE    (1 << SECTION_SHIFT) // 2 Megabytes

#define LOW_MEMORY      (2 * SECTION_SIZE) // 4 Megabytes

#ifndef __ASSEMBLER__

void memzero(unsigned long src, unsigned long n);

#endif /*__ASSEMBLER__*/

#endif /*_MM_H*/
