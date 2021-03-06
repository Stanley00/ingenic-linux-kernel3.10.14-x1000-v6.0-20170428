#ifndef __CPU_H__
#define __CPU_H__
static void set_resume_pc(unsigned int resume_pc) {
	unsigned int cpu_no,opcr;
	unsigned int reim,ctrl;
	unsigned int addr;
	/* Clear previous reset status */
	cpm_outl(0,CPM_RSR);

	/* OPCR.PD and OPCR.L2C_PD */
	cpu_no = read_c0_ebase() & 1;

	opcr = cpm_inl(CPM_OPCR);
	//p 0 or 1 powerdown
	opcr &= ~(3<<25);
	opcr |= (cpu_no + 1) << 25; /* both big and small core power down*/
	cpm_outl(opcr,CPM_OPCR);
	/* serial_put_hex(cpm_inl(CPM_OPCR)); */
	/* serial_put_hex(opcr); */

	ctrl = get_smp_ctrl();
	ctrl |= 1 << (cpu_no + 8);
	set_smp_ctrl(ctrl);

	reim = get_smp_reim();
	reim &= ~(0xffff << 16);
	reim |= (unsigned int)resume_pc & (0xffff << 16);
	set_smp_reim(reim);
	/*
	 * The function of this register:
	 * store sleep wake RPC low 16bit,
	 * reim store high 16bit
	 */
	addr = __read_32bit_c0_register($12, 7);
	__write_32bit_c0_register($12, 7, (unsigned int)resume_pc & (0xffff));

}
#endif	/* __CPU_H__ */
