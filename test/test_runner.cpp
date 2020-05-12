#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace CppUnit;

int main()
{
    TextUi::TestRunner runner;
    TestFactoryRegistry &registry = TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    runner.run();
    return 0;
}