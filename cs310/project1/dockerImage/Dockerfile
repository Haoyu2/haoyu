# Get the gradescope image
FROM gradescope/auto-builds:ubuntu-20.04

# Install jdk, download lib files, and other preparations
RUN apt-get update && apt-get install -y openjdk-11-jdk \
    && wget https://swamiiyer.net/teaching/junit-platform-console-standalone-1.6.2.jar -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/checkstyle-suppressions.xml -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/apiguardian-api-1.1.0.jar -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/checkstyle-8.21-all.jar -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/json-simple-3.1.1.jar -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/checkstyle-lift.jar -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/checkstyle.xml -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/check_style -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/stdlib.jar -P /autograder/source/lib \
    && wget https://swamiiyer.net/teaching/dsa.jar -P /autograder/source/lib \
    && sed -i 's|${PROJECT_HOME}|/autograder/source|g' /autograder/source/lib/check_style \
    && sed -i 's|${HOME}|/autograder/source|g' /autograder/source/lib/check_style \
    && mv /autograder/source/lib/check_style /bin/check_style \
    && chmod 755 /bin/check_style

# Temporary: copy testutils.jar (to be uploaded to /teaching when complete)
COPY testutils.jar /autograder/source/lib/testutils.jar

# copy over the necessary files and folders
COPY run_autograder /autograder/run_autograder
COPY src /autograder/source/src
COPY data /autograder/source/data
WORKDIR /autograder