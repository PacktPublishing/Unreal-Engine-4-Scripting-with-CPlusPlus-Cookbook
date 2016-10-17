REM erases unnecessary files

rmdir .\Binaries /s /q
rmdir .\Intermediate\Build /s /q
rmdir .\Intermediate\ProjectFiles/obj /s /q
rmdir .\Intermediate\ReimportCache /s /q
erase .\Intermediate\CachedAssetRegistry.bin /q

rmdir .\Saved\Autosaves /s /q
rmdir .\Saved\Backup /s /q
rmdir .\Saved\Config/WorldState /s /q
rmdir .\Saved\Logs /s /q
rmdir .\Saved\Stats /s /q

pause
