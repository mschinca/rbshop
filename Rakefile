require "bundler/gem_tasks"

require "rake/extensiontask"

Rake::ExtensionTask.new("rbshop") do |ext|
  ext.lib_dir = "lib/rbshop"
end

task :default => [:clean, :compile]
