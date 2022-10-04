# MyProject
Its Intent Recognizer Project
Code Compilation Steps:
1. Clone IntentRecognizer proejct/repo and get latest project
2. Code is buildable with cd IntentRecognizer repro, mkdir build && cd build && cmake .. && make command
3. Above steps will build code and it will create IntentRecognier bin, you have to run it as ./IntentRecognier
4. After running it type commands for weather or fact related, then it will return user Intent
5. It will run in loop and ask for user to type commands. for exit you have to type "cancel"

Unit Testing: GTest
1. For unit testing pass -DCMAKE_UNITTEST="UTEST" with cmake .. like cmake ..  -DCMAKE_UNITTEST="UTEST"
2. One file main_test.cpp added for GTest, but it is not verified, as I was facing some issue with my ubantu setup
3. Pardon for unit test part is not verified
