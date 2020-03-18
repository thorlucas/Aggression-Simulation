# Aggression Simulation

Uses the [Bromine](https://github.com/thorlucas/Bromine) game engine.

## TODO for Bromine

- Had to `mkdir lib` and `include`
- Had to specify `CreatureLogicTrait::owner()` in constructor because owner is name of the parameter
- Owner parameter is confusing and prone to breakage, consider making it protected and setting by the render server?
- Perhaps smart pointer vector type that allows references to be set in initialization instead of constructor? Move all user defined parameters to `initialize()` instead of constructor and allow constructor to handle back-end stuff?
- Getting scene root node reference is redundant — make the instance a reference?
- Do texture indexing by path so that the same texture is not loaded multiple times
- Random utility is needed so we don't have to `srand(time(NULL))` in every logic trait
- Node equality by ID.
- `Bromine::server<RenderServer>().loadTexture` is a little bit awkward, too. As is `Bromine::instance().renderServer`. Maybe all servers should be singletons or accessible via static methods?
- Using a `ResourceID` is strange. Maybe return a `Resource&`?
- Nodes need access to their scene.
- Ok, so we have two options. Put scene-logic in the root node, in a seperate logic node, or in the scene itself. It seems like the right thing to do to put it in a node, not in the scene itself. How can we discourage this?
- We need a late update and early update function for logic server. For example, we want one node to check on the statuses of other nodes on the scene. This could be affected by when updates happen, meaning that this would happen after.
- Breaks for some reason if we call `addChild` in `loadScene`
- We should be able to make multiple instances of one node, like a prefab in unity.
- LOL HOW IS THERE NO WAY TO REMOVE A NODE
- Adding a render trait after the thing started does not trigger an update to the render list