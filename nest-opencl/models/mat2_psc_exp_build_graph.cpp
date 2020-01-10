#include "mat2_psc_exp.h"
#include "model_gpu.h"
#include "kernel_manager.h"

void nest::mat2_psc_exp::handle(BuildGraphEvent &e)
{
  index sgid = e.get_sender_gid() - 1;
  index tgid = this->get_gid() - 1;
  double weight = e.get_weight();
  int thrd = kernel().vp_manager.get_thread_id();

  kernel().simulation_manager.gpu_execution[thrd]->handle(sgid, tgid, weight);
}
