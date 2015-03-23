#ifndef PIC
#define PIC 1

void acknowledge_interrupt(int vector);
void initalize_pic(int master_vector_offset,int slave_vector_offset);
void clear_mask(unsigned char IRQline);
void set_mask(unsigned char IRQline);

#endif
