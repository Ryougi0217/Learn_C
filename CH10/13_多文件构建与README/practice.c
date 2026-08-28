#include <stdio.h>
#include "report.h"

int main(void)
{
    printf("%s\n", report_score(88) ? "pass" : "fail");
    return 0;
}

