cmake_minimum_required(VERSION 3.10)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Project name
project(charley C)

# List of source files
set(SRC
        src/duplicateLink.c src/addConnectivityRecord.c src/addLink.c src/addNode.c src/addRouteLink.c
        src/addRouteRecord.C src/addTrafficRecord.C src/charleyInit.C src/charley.c src/checkArguments.c
        src/countLinks.c src/connectivityRecord.c src/connectivity.c src/copyLink.c src/copyNetwork.c
        src/cont.c src/copyRouteLink.c src/delay.c src/deleteConnectivityRecord.c src/deleteLinks.c
        src/deleteNodes.c src/deleteRouteLinks.C src/deleteRoute.C src/deleteTraffic.c
        src/duplicateString.c src/evolve.c src/filename.c src/findBest.c src/findNode.c src/findRouteRecord.c
        src/fitness.c src/increaseBuffer.c src/iniValue.c src/link.c src/logger.c src/mate.c src/makeLinks.c
        src/makeNetwork.c src/makeNodes.c src/makePopulation.c src/makeTraffic.c src/network.c src/networkParameter.C
        src/node.c src/population.c src/printConnectionRecord.c src/printLinks.c src/printNetwork.c
        src/printNodes.c src/printParameters.c src/printPopulation.c src/printRoutLink.c
        src/printRouteRecord.c src/printTraffic.c src/randomCost.c src/randomLink.c src/randomMessage.c
        src/randomMessageLength.c src/randomNode.c src/randomNumber.c src/randomSpeed.c src/readLine.c
        src/resetLink.c src/resetNode.c src/route.c src/routes.c src/routeLink.c src/selectLink.c src/traffic.c
)

# Include directories
include_directories(src/include)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")

# Add executable
add_executable(charley ${SRC})

# Link libraries
target_link_libraries(charley PRIVATE m)