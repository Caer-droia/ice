#
# Copyright (c) ZeroC, Inc. All rights reserved.
#

$(test)_sliceflags              := -I$(test)
$(test)_client_sources          = Client.m ObjectsForward.ice ObjectsTest.ice ObjectsDerived.ice \
                                  ObjectsDerivedEx.ice TestI.m AllTests.m
$(test)_server_sources          = Server.m ObjectsForward.ice ObjectsTest.ice ObjectsDerived.ice \
                                  ObjectsDerivedEx.ice TestI.m TestIntfI.m
$(test)_collocated_sources      = Collocated.m ObjectsForward.ice ObjectsTest.ice ObjectsDerived.ice \
                                  ObjectsDerivedEx.ice TestI.m TestIntfI.m AllTests.m

tests += $(test)
