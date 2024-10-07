int __libc_start_main (
      int (*main) (int, char **, char **),
      int argc,
      char * __unbounded *__unbounded ubp_av,
      __typeof (main) init,
      void (*fini) (void),
      void (*rtld_fini) (void),
      void * __unbounded stack_end)
  {
  #if __BOUNDED_POINTERS__
      char **argv
  #else
  # define argv ubp_av
  #endif
      int result;
  }
