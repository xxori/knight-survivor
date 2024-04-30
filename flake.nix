{
  description = "A C++ environment for UoA OOP Projects";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = import nixpkgs { inherit system; };

      in
      {
  devShells.default = pkgs.mkShell.override {stdenv = pkgs.llvmPackages_18.stdenv;} {
          name = "OOP Major Prac";
          packages = with pkgs;
            [
              clang-tools_18
	      llvmPackages_18.libcxx
	      raylib
	      cmake
            ];
        };
      }
    );
}
