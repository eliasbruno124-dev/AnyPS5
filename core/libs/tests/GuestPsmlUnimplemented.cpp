#include "prx/libc/include/general/VabiMacros.hpp"
#include <array>
#include <cstdlib>
#include <string>

extern "C" {
int APS5_VABI scePsmlMfsrInit();
int APS5_VABI scePsmlMfsrGetDispatchMfsrPacket1000();
int APS5_VABI scePsmlMfsrGetDispatchMfsrPacketSizeInDwords();
int APS5_VABI scePsmlMfsrReleaseContext();
int APS5_VABI scePsmlUnknown__P2KpvixvL6E();
int APS5_VABI scePsmlUnknown_ArakEpzsZo0();
int APS5_VABI scePsmlUnknown_FSGaTQze0UY();
int APS5_VABI scePsmlUnknown_GHna9_MDvnUk();
int APS5_VABI scePsmlUnknown_GJY0MvuTcs8();
int APS5_VABI scePsmlUnknown_LXq_P6mIxpCw();
int APS5_VABI scePsmlUnknown_RUNLFro_Pqok();
int APS5_VABI scePsmlUnknown_eWoKNeB6V_Mk();
int APS5_VABI scePsmlUnknown_gxv3i_PMTEzU();
int APS5_VABI scePsmlUnknown_jEevBXmagOQ();
}

namespace {

using PsmlFunction = int (APS5_VABI *)();

struct UnimplementedCall {
    PsmlFunction function;
    const char* name;
};

}

int main(int argc, char** argv) {
    if (argc != 2) return 2;
    const std::array calls{
        UnimplementedCall{scePsmlMfsrInit, "scePsmlMfsrInit"},
        UnimplementedCall{scePsmlMfsrGetDispatchMfsrPacket1000, "scePsmlMfsrGetDispatchMfsrPacket1000"},
        UnimplementedCall{scePsmlMfsrGetDispatchMfsrPacketSizeInDwords, "scePsmlMfsrGetDispatchMfsrPacketSizeInDwords"},
        UnimplementedCall{scePsmlMfsrReleaseContext, "scePsmlMfsrReleaseContext"},
        UnimplementedCall{scePsmlUnknown__P2KpvixvL6E, "scePsmlUnknown__P2KpvixvL6E"},
        UnimplementedCall{scePsmlUnknown_ArakEpzsZo0, "scePsmlUnknown_ArakEpzsZo0"},
        UnimplementedCall{scePsmlUnknown_FSGaTQze0UY, "scePsmlUnknown_FSGaTQze0UY"},
        UnimplementedCall{scePsmlUnknown_GHna9_MDvnUk, "scePsmlUnknown_GHna9_MDvnUk"},
        UnimplementedCall{scePsmlUnknown_GJY0MvuTcs8, "scePsmlUnknown_GJY0MvuTcs8"},
        UnimplementedCall{scePsmlUnknown_LXq_P6mIxpCw, "scePsmlUnknown_LXq_P6mIxpCw"},
        UnimplementedCall{scePsmlUnknown_RUNLFro_Pqok, "scePsmlUnknown_RUNLFro_Pqok"},
        UnimplementedCall{scePsmlUnknown_eWoKNeB6V_Mk, "scePsmlUnknown_eWoKNeB6V_Mk"},
        UnimplementedCall{scePsmlUnknown_gxv3i_PMTEzU, "scePsmlUnknown_gxv3i_PMTEzU"},
        UnimplementedCall{scePsmlUnknown_jEevBXmagOQ, "scePsmlUnknown_jEevBXmagOQ"},
    };
    for (const auto& call : calls) {
        if (argv[1] == std::string(call.name)) {
            (void)call.function();
            return 2;
        }
    }
    return 2;
}
