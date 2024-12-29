#include "Bfinders.h"

int main() {
	const uint64_t SEED = 8675309;
	const int OVERWORLD_STRUCTURES[] = {
		Ancient_City,
		Desert_Pyramid,
		Igloo,
		Jungle_Pyramid,
		Mansion,
		Monument,
		Outpost,
		Ruined_Portal, 
		Shipwreck,
		Swamp_Hut,
		/* Treasure, */ // Not supported yet
		Village
	};
	const int NETHER_STRUCTURES[] = {
		Bastion,  // Not differentiated from fortresses yet
		Fortress, // Not differentiated from bastions yet
		Ruined_Portal_N
	};
	const int END_STRUCTURES[] = {
		End_City
	};
	const int REGION_RADIUS = 7;

	Generator g;
	setupGenerator(&g, MC_NEWEST, 0);
	applySeed(&g, DIM_OVERWORLD, SEED);
	// g.platform = PLATFORM_JAVA;

	StructureConfig sconf;
	Pos pos;

	for (int regionX = -REGION_RADIUS; regionX <= REGION_RADIUS; ++regionX) {
		for (int regionZ = -REGION_RADIUS; regionZ <= REGION_RADIUS; ++regionZ) {
			for (size_t i = 0; i < sizeof(OVERWORLD_STRUCTURES)/sizeof(*OVERWORLD_STRUCTURES); ++i) {
				if (!getBedrockStructureConfig(OVERWORLD_STRUCTURES[i], g.mc, &sconf)) {
					printf("ERR: %s's configuration could not be found.\n", struct2str(OVERWORLD_STRUCTURES[i]));
					continue;
				}
				if (!getBedrockStructurePos(OVERWORLD_STRUCTURES[i], g.mc, g.seed, regionX, regionZ, &pos)) {
					// printf("ERR: Position for %s in region (%d, %d) ((%d, %d) - (%d, %d)) could not be determined.\n", struct2str(OVERWORLD_STRUCTURES[i]), regionX, regionZ, regionX * sconf.regionSize * 16, regionZ * sconf.regionSize * 16, (regionX + 1) * sconf.regionSize * 16 - 1, (regionZ + 1) * sconf.regionSize * 16 - 1);
					continue;
				}
				// TODO: Investigate Chunkbase's isViableStructureTerrain for mansions
				if (OVERWORLD_STRUCTURES[i] && (!isViableStructurePos(OVERWORLD_STRUCTURES[i], &g, pos.x, pos.z, 0) || !isViableStructureTerrain(OVERWORLD_STRUCTURES[i], &g, pos.x, pos.z))) continue;
				printf("%s: (%d, %d)\n", struct2str(OVERWORLD_STRUCTURES[i]), pos.x, pos.z);
			}

			// StructureVariant sv;
			// if (!getBedrockRavinePos(SEED, regionX, regionZ, &sv)) continue;
			// printf("Ravine: (%d, %d, %d)\n", sv.x, sv.y, sv.z);
		}
	}

	applySeed(&g, DIM_NETHER, SEED);
	for (int regionX = -REGION_RADIUS; regionX <= REGION_RADIUS; ++regionX) {
		for (int regionZ = -REGION_RADIUS; regionZ <= REGION_RADIUS; ++regionZ) {
			for (size_t i = 0; i < sizeof(NETHER_STRUCTURES)/sizeof(*NETHER_STRUCTURES); ++i) {
				if (!getBedrockStructureConfig(NETHER_STRUCTURES[i], g.mc, &sconf)) {
					printf("ERR: %s's configuration could not be found.\n", struct2str(NETHER_STRUCTURES[i]));
					continue;
				}
				if (!getBedrockStructurePos(NETHER_STRUCTURES[i], g.mc, g.seed, regionX, regionZ, &pos)) {
					// printf("ERR: Position for %s in region (%d, %d) ((%d, %d) - (%d, %d)) could not be determined.\n", struct2str(NETHER_STRUCTURES[i]), regionX, regionZ, regionX * sconf.regionSize * 16, regionZ * sconf.regionSize * 16, (regionX + 1) * sconf.regionSize * 16 - 1, (regionZ + 1) * sconf.regionSize * 16 - 1);
					continue;
				}
				if (!isViableStructurePos(NETHER_STRUCTURES[i], &g, pos.x, pos.z, 0)) continue;
				printf("%s: (%d, %d)\n", struct2str(NETHER_STRUCTURES[i]), pos.x, pos.z);
			}
		}
	}

	SurfaceNoise sn;
	initSurfaceNoise(&sn, DIM_END, SEED);
	applySeed(&g, DIM_END, SEED);
	for (int regionX = -REGION_RADIUS; regionX <= REGION_RADIUS; ++regionX) {
		for (int regionZ = -REGION_RADIUS; regionZ <= REGION_RADIUS; ++regionZ) {
			for (size_t i = 0; i < sizeof(END_STRUCTURES)/sizeof(*END_STRUCTURES); ++i) {
				if (!getBedrockStructureConfig(END_STRUCTURES[i], g.mc, &sconf)) {
					printf("ERR: %s's configuration could not be found.\n", struct2str(END_STRUCTURES[i]));
					continue;
				}
				if (!getBedrockStructurePos(END_STRUCTURES[i], g.mc, g.seed, regionX, regionZ, &pos)) {
					// printf("ERR: Position for %s in region (%d, %d) ((%d, %d) - (%d, %d)) could not be determined.\n", struct2str(END_STRUCTURES[i]), regionX, regionZ, regionX * sconf.regionSize * 16, regionZ * sconf.regionSize * 16, (regionX + 1) * sconf.regionSize * 16 - 1, (regionZ + 1) * sconf.regionSize * 16 - 1);
					continue;
				}
				if (!isViableStructurePos(END_STRUCTURES[i], &g, pos.x, pos.z, 0) /* || !isViableEndCityTerrain(&g, &sn, pos.x, pos.z) */) continue;
				printf("%s: (%d, %d)\n", struct2str(END_STRUCTURES[i]), pos.x, pos.z);
			}
		}
	}

	return 0;
}