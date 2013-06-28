
#ifdef __cplusplus
extern "C" {
#endif

/* primary entry point */
__declspec(section ".init") extern void __boot(int argc, char **argv, char **envp);
extern asm void __start(register int argc, register char **argv, register char **envp);

#ifdef __cplusplus
}
#endif


asm void __boot(register int argc, register char **argv, register char **envp)
{
    nofralloc  /* explicitly no stack */
    /* frame allocation */
    /* call standard application initialization */
    e_bl __start
}
